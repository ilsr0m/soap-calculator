#include "DatabaseManager.h"

RepositoryManager::RepositoryManager(IRepositoryManageable *repository) {
    if(repository) {
        repository->load();
        _lipids      = repository->repository().lipids;
        _acids       = repository->repository().acids;
        _additives   = repository->repository().additives;
    }
}

const LipidContainer&    RepositoryManager::lipids()    const { return _lipids;    }
const AcidContainer&     RepositoryManager::acids()     const { return _acids;     }
const AdditiveContainer& RepositoryManager::additives() const { return _additives; }
