#include "lipid_model.h"
#include "app_settings.h"
#include <algorithm>

LipidModel::LipidModel(QObject *parent)
    : QAbstractListModel(parent)
{
    connect(&AppSettings::instance(), &AppSettings::languageChanged, this, [this]() {
        if(_lipids.empty())
            return;
        emit dataChanged(index(0), index(rowCount() - 1), _roles);

        beginResetModel();

        std::sort(_lipids.begin(), _lipids.end(), [](const LipidProfile &a, const LipidProfile &b) {
            const QString lang = AppSettings::instance().language();
            return a.name.value(lang).localeAwareCompare(b.name.value(lang)) < 0;
        });

        endResetModel();
    });
}

void LipidModel::setModel(const QVariant &data)
{
    if (!data.canConvert<LipidContainer>()) {
        qWarning() << "Invalid data type for AdditiveModel";
        return;
    }
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

    if (!_lipids.contains(lipid))
        return QVariant();

    switch(role) {
        case NameRole:
            return lipid.name.value(AppSettings::instance().language());
        case TypeRole:
            return lipid.type.value(AppSettings::instance().language());
        case IdRole:
            return lipid.id;
    }
    return QVariant();
}

QHash<int, QByteArray> LipidModel::roleNames() const
{
    return {
        {NameRole, "name"},
        {TypeRole, "type"},
        {IdRole  , "id"}
    };
}


