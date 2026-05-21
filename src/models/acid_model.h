#ifndef ACID_MODEL_H
#define ACID_MODEL_H

#include <QObject>
#include <QAbstractListModel>

#include "soap_params.h"

class AcidModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit AcidModel(QObject *parent = nullptr);

    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameEnRole,
        NameRuRole
    };

    void setModel(const QVariant& data);

    int rowCount(const QModelIndex& parent = {}) const override;
    QVariant data(const QModelIndex& index, int role) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QAcidMap _acids;
    QStringList _ids;
};

#endif // ACID_MODEL_H
