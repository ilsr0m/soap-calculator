#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include "SoapTypes.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class DatabaseManager
{
public:
    DatabaseManager();
    ~DatabaseManager();

    bool open(const QString& path);

    LipidContainer& lipids();
    AcidContainer& acids();
    AdditiveContainer& additives();

    DatabaseManager& loadLipids();
    DatabaseManager& loadAcids();
    DatabaseManager& loadAdditives();

    // bool insertLipid(const Lipid& lipid);
    // bool insertAcid();
    // bool insertIngredient();

    // const LipidContainer&     lipids()    const;
    // const AcidContainer&      acids()     const;
    // const AdditiveContainer&  additives() const;

private:
    QSqlDatabase _db;

    LipidContainer _lipids;
    AcidContainer _acids;
    AdditiveContainer _additives;
};

#endif // DATABASEMANAGER_H
