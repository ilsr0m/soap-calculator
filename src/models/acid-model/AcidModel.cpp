#include "AcidModel.h"

#include "AppSettings.h"
#include "ModelRoles.h"

AcidModel::AcidModel(QObject *parent)
    : QAbstractListModel(parent)
{
    connect(&AppSettings::instance(), &AppSettings::languageChanged, this, [this]() {
        if(_acids.empty()) return;
        emit dataChanged(index(0), index(rowCount() - 1), { Roles::NameRole });
    });
}

void AcidModel::setModel(const QVariant &data)
{
    if (!data.canConvert<AcidContainer>()) {
        qWarning() << "Invalid data type for AcidModel";
        return;
    }

    beginResetModel();
    _acids = data.value<AcidContainer>();
    endResetModel();
}

int AcidModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return _acids.count();
}

QVariant AcidModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() < 0 || index.row() >= _acids.size())
        return QVariant();

    // const QString& id = _acids[index.row()];
    const AcidProfile& acid = _acids[index.row()];

    switch(role) {
        case Roles::NameRole:
            return acid.name.value(AppSettings::instance().language());
        case Roles::IdRole:
            return acid.id;
        case Roles::CheckedRole:
            return _checkedItems.contains(acid.id);
    }
    return QVariant();
}

bool AcidModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || index.row() < 0 || index.row() >= _acids.size())
        return false;

    auto& item = _acids[index.row()];
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


QHash<int, QByteArray> AcidModel::roleNames() const
{
    return {
        {Roles::NameRole, "name"},
        {Roles::IdRole  , "id"  },
        {Roles::CheckedRole, "checked"}
    };
}

void AcidModel::sortByCurrentLanguage()
{
    // const QString lang = AppSettings::instance().language();
    // std::sort(_acids.begin(), _acids.end(), [&lang](const AcidProfile &a, const AcidProfile &b) {
    //     return a.name.value(lang).localeAwareCompare(b.name.value(lang)) < 0;
    // });
}
