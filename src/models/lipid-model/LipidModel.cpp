#include "LipidModel.h"
#include "AppSettings.h"
#include "ModelRoles.h"

LipidModel::LipidModel(QObject *parent)
    : QAbstractListModel(parent)
{
    connect(&AppSettings::instance(), &AppSettings::languageChanged, this, [this]() {
        if(_lipids.empty())
            return;
        emit dataChanged(index(0), index(rowCount() - 1), { Roles::NameRole });
    });
}

void LipidModel::setModel(const QVariant &data)
{
    if (!data.canConvert<LipidContainer>()) {
        qWarning() << "Invalid data type for AdditiveModel";
        return;
    }

    beginResetModel();
    _lipids = data.value<LipidContainer>();
    endResetModel();
}

int LipidModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return _lipids.count();
}

QVariant LipidModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() < 0 || index.row() >= _lipids.size())
        return QVariant();

    // const QString& id = ;
    const LipidProfile& lipid = _lipids[index.row()];

    // if (!_lipids.contains(lipid))
    //     return QVariant();

    switch(role) {
        case Roles::NameRole:
            return lipid.name.value(AppSettings::instance().language());
        case Roles::TypeRole:
            return lipid.type.value(AppSettings::instance().language());
        case Roles::CheckedRole:
            return _checkedItems.contains(lipid.id);
        case Roles::IdRole:
            return lipid.id;
    }
    return QVariant();
}

bool LipidModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || index.row() < 0 || index.row() >= _lipids.size())
        return false;

    auto& item = _lipids[index.row()];
    switch (role) {
        case Roles::NameRole:
            item.name.value(AppSettings::instance().language()) = value.toString();
            emit dataChanged(index, index, { Roles::NameRole });
            return true;
        case Roles::CheckedRole:
            bool checked  = value.toBool();
            if(checked) _checkedItems.insert(item.id);
            else _checkedItems.remove(item.id);

            emit dataChanged(index, index, { Roles::CheckedRole });
            return true;
    }

    return false;
}

QHash<int, QByteArray> LipidModel::roleNames() const
{
    return {
        {Roles::NameRole   , "name"   },
        {Roles::TypeRole   , "type"   },
        {Roles::IdRole     , "id"     },
        {Roles::CheckedRole, "checked"}
    };
}


