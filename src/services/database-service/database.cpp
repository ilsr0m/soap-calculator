#include "database.h"

Database::Database(IRepository *repository) {
    if(repository) {
        repository->load();
        _lipidProfiles      = repository->repository().lipids;
        _acidProfiles       = repository->repository().acids;
        _additiveProfiles   = repository->repository().additives;
    }
}

const QMap<QString, LipidProfile>& Database::lipids() const
{
    return _lipidProfiles;
}

const QMap<QString, AcidProfile>& Database::acids() const
{
    return _acidProfiles;
}

const QMap<QString, AdditiveProfile>& Database::additives() const
{
    return _additiveProfiles;
}
