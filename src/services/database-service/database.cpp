#include "database.h"

Database::Database(IRepository *repository) {
    if(repository) {
        repository->load();
        _lipidProfiles      = repository->repository().lipids;
        _acidProfiles       = repository->repository().acids;
        _additiveProfiles   = repository->repository().additives;
    }
}

const QLipidMap&    Database::lipids()    const { return _lipidProfiles;    }
const QAcidMap&     Database::acids()     const { return _acidProfiles;     }
const QAdditiveMap& Database::additives() const { return _additiveProfiles; }
