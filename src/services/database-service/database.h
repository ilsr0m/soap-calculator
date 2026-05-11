#ifndef DATABASE_H
#define DATABASE_H

#include "irepository.h"

class Database
{
public:
    Database(IRepository *repository);

    const QMap<QString, LipidProfile>& lipids() const;
    const QMap<QString, AcidProfile>& acids() const;
    const QMap<QString, AdditiveProfile>& additives() const;

private:
    QMap<QString, LipidProfile> _lipidProfiles;
    QMap<QString, AcidProfile> _acidProfiles;
    QMap<QString, AdditiveProfile> _additiveProfiles;
};

#endif // DATABASE_H
