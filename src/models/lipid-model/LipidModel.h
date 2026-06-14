#ifndef LIPIDMODEL_H
#define LIPIDMODEL_H

#include <QObject>
#include <QAbstractListModel>

#include "SoapTypes.h"

class LipidModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit LipidModel(QObject * parent = nullptr);
    void setModel(const QVariant& data);

    int rowCount(const QModelIndex& parent = {}) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    LipidContainer _lipids;
    QSet<qint32> _checkedItems;
};

#endif // SOAP_CORE_H
