#ifndef LIPID_MODEL_H
#define LIPID_MODEL_H

#include <QObject>
#include <QAbstractListModel>

#include "soap_params.h"

class LipidModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit LipidModel(QObject * parent = nullptr);

    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole,
        TypeRole
    };

    void setModel(const QVariant& data);

    int rowCount(const QModelIndex& parent = {}) const override;
    QVariant data(const QModelIndex& index, int role) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    LipidContainer _lipids;
    QList<int> _roles = {IdRole, NameRole, TypeRole};
};

#endif // SOAP_CORE_H
