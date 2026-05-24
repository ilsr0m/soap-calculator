#ifndef DATABASE_H
#define DATABASE_H

#include "irepository.h"

class Database
{
public:
    Database(IRepository *repository);

    const LipidContainer&     lipids()    const;
    const AcidContainer&      acids()     const;
    const AdditiveContainer&  additives() const;

private:
    LipidContainer    _lipidProfiles;
    AcidContainer     _acidProfiles;
    AdditiveContainer _additiveProfiles;
};

#endif // DATABASE_H
