#ifndef ADDITIVEMODEL_H
#define ADDITIVEMODEL_H

#include <QObject>
#include <QAbstractListModel>

#include "SoapTypes.h"

class AdditiveModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit AdditiveModel(QObject *parent = nullptr);

    void setModel(const QVariant &data);

    int rowCount(const QModelIndex& parent = {}) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

protected:
    QHash<int, QByteArray> roleNames() const override;
private:
    AdditiveContainer _additives;
    QSet<qint32> _checkedItems;
};

#endif // ACID_MODEL_H
