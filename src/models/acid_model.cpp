#include "acid_model.h"

AcidModel::AcidModel(QObject *parent) : QAbstractListModel(parent) {}

void AcidModel::setModel(const QVariant &data)
{
    if (!data.canConvert<QAcidMap>()) {
        qWarning() << "Invalid data type for AdditiveModel";
        return;
    }

    _acids = data.value<QAcidMap>();
    _ids = _acids.keys();
    _ids.sort();
    endResetModel();
}

int AcidModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return _ids.count();
}

QVariant AcidModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() < 0 || index.row() >= _ids.size())
        return QVariant();

    const QString& id = _ids[index.row()];
    const AcidProfile& acid = _acids[id];

    if (!_acids.contains(id))
        return QVariant();

    switch(role) {
    case NameEnRole:
        return acid.name.en;
    case NameRuRole:
        return acid.name.ru;
    case IdRole:
        return id;
    }
    return QVariant();
}

QHash<int, QByteArray> AcidModel::roleNames() const
{
    return {
        {NameEnRole, "nameEn"},
        {NameRuRole, "nameRu"},
        {IdRole, "id"}
    };
}
