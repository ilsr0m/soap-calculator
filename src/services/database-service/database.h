#ifndef DATABASE_H
#define DATABASE_H

#include "irepository.h"

class Database
{
public:
    Database(IRepository *repository);

    const QLipidMap&     lipids()    const;
    const QAcidMap&      acids()     const;
    const QAdditiveMap&  additives() const;

private:
    QLipidMap    _lipidProfiles;
    QAcidMap     _acidProfiles;
    QAdditiveMap _additiveProfiles;
};

#endif // DATABASE_H
