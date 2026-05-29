#ifndef IREPOSITORYMANAGEABLE_H
#define IREPOSITORYMANAGEABLE_H

#include "soap_params.h"

struct RepositoryEntities
{
    LipidContainer lipids;
    AcidContainer acids;
    AdditiveContainer additives;
};

class IRepositoryManageable
{
public:
    virtual ~IRepositoryManageable() = default;
    virtual void load() = 0;

    inline const RepositoryEntities& repository() const { return _repository; }

protected:
    RepositoryEntities _repository;
};


#endif // IREPOSITORYMANAGEABLE_H
