#include "acid_model.h"
#include "app_settings.h"

AcidModel::AcidModel(QObject *parent)
    : QAbstractListModel(parent)
{
    connect(&AppSettings::instance(), &AppSettings::languageChanged, this, [this]() {
        if(_acids.empty())
            return;
        emit dataChanged(index(0), index(rowCount() - 1), _roles);

        beginResetModel();

        std::sort(_acids.begin(), _acids.end(), [](const AcidProfile &a, const AcidProfile &b) {
            const QString lang = AppSettings::instance().language();
            return a.name.value(lang).localeAwareCompare(b.name.value(lang)) < 0;
        });

        endResetModel();
    });
}

void AcidModel::setModel(const QVariant &data)
{
    if (!data.canConvert<AcidContainer>()) {
        qWarning() << "Invalid data type for AcidModel";
        return;
    }
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

    if (!_acids.contains(acid))
        return QVariant();

    switch(role) {
        case NameRole:
            return acid.name.value(AppSettings::instance().language());
        case IdRole:
            return acid.id;
    }
    return QVariant();
}


QHash<int, QByteArray> AcidModel::roleNames() const
{
    return {
        {NameRole, "name"},
        {IdRole  , "id"  }
    };
}
