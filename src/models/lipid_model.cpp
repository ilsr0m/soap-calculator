#include "lipid_model.h"

LipidModel::LipidModel(QObject *parent) : QAbstractListModel(parent) {}

int LipidModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return _ids.count();
}

QVariant LipidModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() < 0 || index.row() >= _ids.size())
        return QVariant();

    const QString& id = _ids[index.row()];
    const LipidProfile& lipid = _lipids[id];

    if (!_lipids.contains(id))
        return QVariant();

    switch(role) {
        case NameEnRole:
            return lipid.name.en;
        case NameRuRole:
            return lipid.name.ru;
        case IdRole:
            return id;
    }
    return QVariant();
}

QHash<int, QByteArray> LipidModel::roleNames() const
{
    return {
        {NameEnRole, "nameEn"},
        {NameRuRole, "nameRu"},
        {IdRole, "id"}
    };
}

void LipidModel::setModel(const QVariant &data)
{
    if (!data.canConvert<QLipidMap>()) {
        qWarning() << "Invalid data type for AdditiveModel";
        return;
    }
    _lipids = data.value<QLipidMap>();
    _ids = _lipids.keys();
    _ids.sort();
    endResetModel();
}
