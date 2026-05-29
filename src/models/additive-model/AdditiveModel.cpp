#include "AdditiveModel.h"

#include "AppSettings.h"
#include "model_roles.h"

AdditiveModel::AdditiveModel(QObject *parent)
    : QAbstractListModel(parent)
{
    connect(&AppSettings::instance(), &AppSettings::languageChanged, this, [this]() {
        if(_additives.empty())
            return;
        emit dataChanged(index(0), index(rowCount() - 1), { Roles::NameRole });
    });
}

void AdditiveModel::setModel(const QVariant &data)
{
    if (!data.canConvert<AdditiveContainer>()) {
        qWarning() << "Invalid data type for AdditiveModel";
        return;
    }

    beginResetModel();
    _additives = data.value<AdditiveContainer>();
    endResetModel();
}

int AdditiveModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return _additives.count();
}

QVariant AdditiveModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() < 0 || index.row() >= _additives.size())
        return QVariant();

    // const QString& id = _additives[index.row()];
    const AdditiveProfile& additive = _additives[index.row()];

    switch(role) {
    case Roles::NameRole:
        return additive.name.value(AppSettings::instance().language());
    case Roles::IdRole:
        return additive.id;
    }
    return QVariant();
}

QHash<int, QByteArray> AdditiveModel::roleNames() const
{
    return {
        {Roles::NameRole, "name"},
        {Roles::IdRole, "id"}
    };
}


