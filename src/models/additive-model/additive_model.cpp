#include "additive_model.h"
#include "app_settings.h"

AdditiveModel::AdditiveModel(QObject *parent)
    : QAbstractListModel(parent)
{
    connect(&AppSettings::instance(), &AppSettings::languageChanged, this, [this]() {
        if(_additives.empty())
            return;
        emit dataChanged(index(0), index(rowCount() - 1), _roles);

        beginResetModel();

        std::sort(_additives.begin(), _additives.end(), [](const AdditiveProfile &a, const AdditiveProfile &b) {
            const QString lang = AppSettings::instance().language();
            return a.name.value(lang).localeAwareCompare(b.name.value(lang)) < 0;
        });

        endResetModel();
    });
}

void AdditiveModel::setModel(const QVariant &data)
{
    if (!data.canConvert<AdditiveContainer>()) {
        qWarning() << "Invalid data type for AdditiveModel";
        return;
    }
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

    if (!_additives.contains(additive))
        return QVariant();

    switch(role) {
    case NameRole:
        return additive.name.value(AppSettings::instance().language());
    case IdRole:
        return additive.id;
    }
    return QVariant();
}

QHash<int, QByteArray> AdditiveModel::roleNames() const
{
    return {
        {NameRole, "name"},
        {IdRole, "id"}
    };
}

