#ifndef IREPOSITORY_H
#define IREPOSITORY_H

#include "soap_params.h"

struct RepositoryEntities
{
    LipidContainer lipids;
    AcidContainer acids;
    AdditiveContainer additives;
};

class IRepository
{
public:
    virtual ~IRepository() = default;
    virtual void load() = 0;

    inline const RepositoryEntities& repository() const { return _repository; }

protected:
    RepositoryEntities _repository;
};


#endif // IREPOSITORY_H
