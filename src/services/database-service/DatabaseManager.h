#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include "SoapProfiles.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

/**
 * @brief Manages the database connection and loads ingredient profiles.
 *
 * This class provides functionality for opening an SQLite database and
 * loading reference data for lipids, acids, additives, dyes, aromas,
 * and liquids into their corresponding containers.
 */
class DatabaseManager
{
public:
    /**
     * @brief Constructs a DatabaseManager object.
     */
    DatabaseManager();

    /**
     * @brief Destroys the DatabaseManager object.
     */
    ~DatabaseManager();

    /**
     * @brief Opens a database connection.
     * @param path Path to the SQLite database file.
     * @return `true` if the database was opened successfully; otherwise `false`.
     */
    bool open(const QString& path);

    /**
     * @brief Returns the loaded lipid profiles.
     * @return Reference to the lipid container.
     */
    LipidContainer& lipids();

    /**
     * @brief Returns the loaded acid profiles.
     * @return Reference to the acid container.
     */
    AcidContainer& acids();

    /**
     * @brief Returns the loaded additive profiles.
     * @return Reference to the additive container.
     */
    AdditiveContainer& additives();

    /**
     * @brief Returns the loaded dye profiles.
     * @return Reference to the dye container.
     */
    DyeContainer& dyes();

    /**
     * @brief Returns the loaded aroma profiles.
     * @return Reference to the aroma container.
     */
    AromaContainer& aromas();

    /**
     * @brief Returns the loaded liquid profiles.
     * @return Reference to the liquid container.
     */
    LiquidContainer& liquids();

    /**
     * @brief Loads lipid profiles from the database.
     * @return Reference to this object.
     */
    DatabaseManager& loadLipids();

    /**
     * @brief Loads acid profiles from the database.
     * @return Reference to this object.
     */
    DatabaseManager& loadAcids();

    /**
     * @brief Loads additive profiles from the database.
     * @return Reference to this object.
     */
    DatabaseManager& loadAdditives();

    /**
     * @brief Loads dye profiles from the database.
     * @return Reference to this object.
     */
    DatabaseManager& loadDyes();

    /**
     * @brief Loads aroma profiles from the database.
     * @return Reference to this object.
     */
    DatabaseManager& loadAromas();

    /**
     * @brief Loads liquid profiles from the database.
     * @return Reference to this object.
     */
    DatabaseManager& loadLiquids();

    // bool insertLipid(const Lipid& lipid);
    // bool insertAcid();
    // bool insertIngredient();

    // const LipidContainer&     lipids()    const;
    // const AcidContainer&      acids()     const;
    // const AdditiveContainer&  additives() const;

private:
    /**
     * @brief Database connection.
     */
    QSqlDatabase _db;

    /**
     * @brief Loaded lipid profiles.
     */
    LipidContainer _lipids;

    /**
     * @brief Loaded acid profiles.
     */
    AcidContainer _acids;

    /**
     * @brief Loaded additive profiles.
     */
    AdditiveContainer _additives;

    /**
     * @brief Loaded dye profiles.
     */
    DyeContainer _dyes;

    /**
     * @brief Loaded aroma profiles.
     */
    AromaContainer _aromas;

    /**
     * @brief Loaded liquid profiles.
     */
    LiquidContainer _liquids;
};

#endif // DATABASEMANAGER_H
