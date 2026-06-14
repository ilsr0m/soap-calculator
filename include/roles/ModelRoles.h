#ifndef MODELROLES_H
#define MODELROLES_H

#include <QObject>
#include <QAbstractListModel>

namespace Roles
{
    enum Role
    {
        IdRole = Qt::UserRole + 1,
        NameRole,
        TypeRole,
        CheckedRole
    };
}

#endif
