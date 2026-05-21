#include "additive_model.h"

AdditiveModel::AdditiveModel(QObject *parent) : QAbstractListModel(parent) {}

void AdditiveModel::setModel(const QVariant &data)
{
    if (!data.canConvert<QAdditiveMap>()) {
        qWarning() << "Invalid data type for AdditiveModel";
        return;
    }
    _additives = data.value<QAdditiveMap>();
    _ids = _additives.keys();
    _ids.sort();
    endResetModel();
}

int AdditiveModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return _ids.count();
}

QVariant AdditiveModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() < 0 || index.row() >= _ids.size())
        return QVariant();

    const QString& id = _ids[index.row()];
    const AdditiveProfile& additive = _additives[id];

    if (!_additives.contains(id))
        return QVariant();

    switch(role) {
    case NameEnRole:
        return additive.name.en;
    case NameRuRole:
        return additive.name.ru;
    case IdRole:
        return id;
    }
    return QVariant();
}

QHash<int, QByteArray> AdditiveModel::roleNames() const
{
    return {
        {NameEnRole, "nameEn"},
        {NameRuRole, "nameRu"},
        {IdRole, "id"}
    };
}

