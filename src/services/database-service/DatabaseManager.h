#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "irepository.h"

/**
 * @brief Manages repository data containers.
 *
 * The RepositoryManager class initializes and provides read-only access
 * to lipid, acid, and additive data loaded from a repository.
 */
class RepositoryManager
{
public:
    /**
     * @brief Creates a repository manager.
     *
     * @param repository Pointer to the repository data source.
     */
    RepositoryManager(IRepositoryManageable *repository);

    /**
     * @brief Returns lipid profiles.
     *
     * @return Const reference to the lipid container.
     */
    const LipidContainer&     lipids()    const;

    /**
     * @brief Returns acid profiles.
     *
     * @return Const reference to the acid container.
     */
    const AcidContainer&      acids()     const;

    /**
     * @brief Returns additive profiles.
     *
     * @return Const reference to the additive container.
     */
    const AdditiveContainer&  additives() const;

private:
    LipidContainer    _lipids;
    AcidContainer     _acids;
    AdditiveContainer _additives;
};

#endif // DATABASEMANAGER_H
