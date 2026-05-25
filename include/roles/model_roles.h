#ifndef MODEL_ROLES_H
#define MODEL_ROLES_H

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
