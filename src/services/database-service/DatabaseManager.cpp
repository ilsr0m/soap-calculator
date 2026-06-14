#include "DatabaseManager.h"

#include "AppSettings.h"

DatabaseManager::DatabaseManager() {}

DatabaseManager::~DatabaseManager()
{
    if(_db.isOpen())
        _db.close();
}

bool DatabaseManager::open(const QString &path)
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName(path);
    if (!_db.open()) {
        qDebug() << "Database open error:" << _db.lastError().text();
        return false;
    }
    return true;
}

DatabaseManager &DatabaseManager::loadLipids()
{
    _lipids.clear();

    // Заполняем значения из lipids
    QSqlQuery lipidQuery("SELECT * FROM lipids;");
    while (lipidQuery.next()) {
        LipidProfile profile;
        // Id
        profile.id =  lipidQuery.value("id").toInt();
        // SAP
        profile.sap.sodium    = lipidQuery.value("sap_sodium").toDouble();
        profile.sap.potassium = lipidQuery.value("sap_potassium").toDouble();
        // INCI
        profile.inciSodium    = lipidQuery.value("inci_sodium"   ).toString();
        profile.inciPotassium = lipidQuery.value("inci_potassium").toString();
        // Properties
        profile.properties.hardness     = lipidQuery.value("hardness"    ).toDouble();
        profile.properties.cleansing    = lipidQuery.value("cleansing"   ).toDouble();
        profile.properties.conditioning = lipidQuery.value("conditioning").toDouble();
        profile.properties.bubbly       = lipidQuery.value("bubbly"      ).toDouble();
        profile.properties.creamy       = lipidQuery.value("creamy"      ).toDouble();
        profile.properties.iodine       = lipidQuery.value("iodine"      ).toDouble();
        _lipids.append(profile);
    }

    // Дополняем данными из lipid_translations
    QSqlQuery lipidTranslationQuery("SELECT * FROM lipid_translations;");
    while (lipidTranslationQuery.next()) {
        qint32 id = lipidTranslationQuery.value("id").toInt();

        auto it = std::find_if(_lipids.begin(), _lipids.end(),
                               [id](const LipidProfile& lipidProfile) {
                                   return lipidProfile.id == id;
                               });

        if (it == _lipids.end())
            continue;

        QString field      = lipidTranslationQuery.value("field").toString();
        QString language   = lipidTranslationQuery.value("language").toString();
        QString definition = lipidTranslationQuery.value("definition").toString();

        ComponentName* target = nullptr;

        if(field == "name")
            target = &it->name;
        else if (field == "type")
            target = &it->type;
        else if (field == "comment")
            target = &it->comment;

        if(!target) continue;

        if(language == "ru")
            target->ru = definition;
        else if (language == "en")
            target->en = definition;

    }
    return *this;
}

DatabaseManager &DatabaseManager::loadAcids()
{
    _acids.clear();
    QSqlQuery acidQuery("SELECT * FROM acids;");
    while (acidQuery.next()) {
        AcidProfile profile;
        // Id
        profile.id =  acidQuery.value("id").toInt();
        profile.neutralization.sodium = acidQuery.value("neutralization_naoh").toDouble();
        profile.neutralization.potassium = acidQuery.value("neutralization_koh").toDouble();
        // INCI
        profile.inciSodium = acidQuery.value("inci_sodium").toString();
        profile.inciPotassium = acidQuery.value("inci_potassium").toString();
        _acids.append(profile);
    }

    QSqlQuery acidTranslationQuery("SELECT * FROM acid_translations;");
    while (acidTranslationQuery.next()) {
        qint32 id = acidTranslationQuery.value("id").toInt();

        auto it = std::find_if(_acids.begin(), _acids.end(),
                               [id](const AcidProfile& acidProfile) {
                                   return acidProfile.id == id;
                               });

        if (it == _acids.end())
            continue;

        QString field      = acidTranslationQuery.value("field").toString();
        QString language   = acidTranslationQuery.value("language").toString();
        QString definition = acidTranslationQuery.value("definition").toString();

        ComponentName* target = nullptr;

        if(field == "name")
            target = &it->name;
        else if (field == "comment")
            target = &it->comment;

        if(!target) continue;

        if(language == "ru")
            target->ru = definition;
        else if (language == "en")
            target->en = definition;

    }

    return *this;
}

DatabaseManager &DatabaseManager::loadAdditives()
{
    _additives.clear();
    QSqlQuery additiveQuery("SELECT * FROM additives;");
    while (additiveQuery.next()) {
        AdditiveProfile profile;
        // Id
        profile.id =  additiveQuery.value("id").toInt();
        // INCI
        profile.inci = additiveQuery.value("inci").toString();
        _additives.append(profile);
    }

    QSqlQuery additiveTranslationQuery("SELECT * FROM additive_translations;");
    while (additiveTranslationQuery.next()) {
        qint32 id = additiveTranslationQuery.value("id").toInt();

        auto it = std::find_if(_additives.begin(), _additives.end(),
                               [id](const AdditiveProfile& additiveProfile) {
                                   return additiveProfile.id == id;
                               });

        if (it == _additives.end())
            continue;

        QString field      = additiveTranslationQuery.value("field").toString();
        QString language   = additiveTranslationQuery.value("language").toString();
        QString definition = additiveTranslationQuery.value("definition").toString();

        ComponentName* target = nullptr;

        if(field == "name"){
            target = &it->name;
        }
        else if (field == "type")
            target = &it->type;
        else if (field == "comment")
            target = &it->comment;

        if(!target) continue;

        if(language == "ru")
            target->ru = definition;
        else if (language == "en"){
            target->en = definition;
            qDebug() << target->en;
        }
    }
    return *this;
}

LipidContainer &DatabaseManager::lipids() { return _lipids; }
AcidContainer &DatabaseManager::acids() { return _acids; }
AdditiveContainer &DatabaseManager::additives() { return _additives; }



