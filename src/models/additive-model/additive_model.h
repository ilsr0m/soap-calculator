#ifndef ADDITIVE_MODEL_H
#define ADDITIVE_MODEL_H

#include <QObject>
#include <QAbstractListModel>

#include "soap_params.h"

class AdditiveModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit AdditiveModel(QObject *parent = nullptr);

    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole
    };

    void setModel(const QVariant &data);

    int rowCount(const QModelIndex& parent = {}) const override;
    QVariant data(const QModelIndex& index, int role) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    AdditiveContainer _additives;
    QList<int> _roles = {IdRole, NameRole};
};

#endif // ACID_MODEL_H
