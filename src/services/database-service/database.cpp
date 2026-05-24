#include "database.h"

Database::Database(IRepository *repository) {
    if(repository) {
        repository->load();
        _lipidProfiles      = repository->repository().lipids;
        _acidProfiles       = repository->repository().acids;
        _additiveProfiles   = repository->repository().additives;
    }
}

const LipidContainer&    Database::lipids()    const { return _lipidProfiles;    }
const AcidContainer&     Database::acids()     const { return _acidProfiles;     }
const AdditiveContainer& Database::additives() const { return _additiveProfiles; }
