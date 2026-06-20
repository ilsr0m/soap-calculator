#ifndef ACIDMODEL_H
#define ACIDMODEL_H

#include <QObject>
#include <QAbstractListModel>

#include "SoapTypes.h"

class AcidModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit AcidModel(QObject *parent = nullptr);

    void setModel(const QVariant& data);

    int rowCount(const QModelIndex& parent = {}) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    void sortByCurrentLanguage();

private:
    AcidContainer _acids;
    QSet<qint32> _checkedItems;
    // QList<int> _roles = {Roles::IdRole, Roles::NameRole};
};

#endif // ACIDMODEL_H
