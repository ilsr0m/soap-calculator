#include "DatabaseManager.h"

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
    QSqlQuery query("SELECT * FROM lipids;");
    while (query.next()) {
        LipidProfile profile;
        // Id
        profile.id =  query.value("id").toInt();
        // SAP
        profile.sap.sodium    = query.value("sap_sodium").toDouble();
        profile.sap.potassium = query.value("sap_potassium").toDouble();
        // INCI
        profile.inciSodium    = query.value("inci_sodium"   ).toString();
        profile.inciPotassium = query.value("inci_potassium").toString();

        // Fill with lipid properties
        profile.properties.hardness     = query.value("hardness"    ).toDouble();
        profile.properties.cleansing    = query.value("cleansing"   ).toDouble();
        profile.properties.conditioning = query.value("conditioning").toDouble();
        profile.properties.bubbly       = query.value("bubbly"      ).toDouble();
        profile.properties.creamy       = query.value("creamy"      ).toDouble();
        profile.properties.iodine       = query.value("iodine"      ).toDouble();

        // Fill with fatty acids parameters
        profile.fatties.lauric     = query.value("lauric"       ).toDouble();
        profile.fatties.linoleic   = query.value("linoleic"     ).toDouble();;
        profile.fatties.linolenic  = query.value("linolenic"    ).toDouble();;
        profile.fatties.myristic   = query.value("myristic"     ).toDouble();;
        profile.fatties.oleic      = query.value("oleic"        ).toDouble();;
        profile.fatties.ricinoleic = query.value("ricinoleic"   ).toDouble();;
        profile.fatties.palmitic   = query.value("palmitic"     ).toDouble();;
        profile.fatties.stearic    = query.value("stearic"      ).toDouble();;
        profile.fatties.others     = query.value("other_fatties").toDouble();;

        _lipids.append(profile);
    }

    // Дополняем данными из lipid_translations
    QSqlQuery translationQuery("SELECT * FROM lipid_translations;");
    while (translationQuery.next()) {
        qint32 id = translationQuery.value("id").toInt();

        auto it = std::find_if(_lipids.begin(), _lipids.end(),
                               [id](const LipidProfile& profile) {
                                   return profile.id == id;
                               });

        if (it == _lipids.end())
            continue;

        QString field      = translationQuery.value("field").toString();
        QString language   = translationQuery.value("language").toString();
        QString definition = translationQuery.value("definition").toString();

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
    QSqlQuery query("SELECT * FROM acids;");
    while (query.next()) {
        AcidProfile profile;
        // Id
        profile.id =  query.value("id").toInt();
        profile.neutralization.sodium = query.value("neutralization_naoh").toDouble();
        profile.neutralization.potassium = query.value("neutralization_koh").toDouble();
        // INCI
        profile.inciSodium = query.value("inci_sodium").toString();
        profile.inciPotassium = query.value("inci_potassium").toString();
        _acids.append(profile);
    }

    QSqlQuery translationQuery("SELECT * FROM acid_translations;");
    while (translationQuery.next()) {
        qint32 id = translationQuery.value("id").toInt();

        auto it = std::find_if(_acids.begin(), _acids.end(),
                               [id](const AcidProfile& profile) {
                                   return profile.id == id;
                               });

        if (it == _acids.end())
            continue;

        QString field      = translationQuery.value("field"     ).toString();
        QString language   = translationQuery.value("language"  ).toString();
        QString definition = translationQuery.value("definition").toString();

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
    QSqlQuery query("SELECT * FROM additives;");
    while (query.next()) {
        AdditiveProfile profile;
        profile.id   = query.value("id"  ).toInt   ();
        profile.inci = query.value("inci").toString();
        _additives.append(profile);
    }

    QSqlQuery translationQuery("SELECT * FROM additive_translations;");
    while (translationQuery.next()) {
        qint32 id = translationQuery.value("id").toInt();

        auto it = std::find_if(_additives.begin(), _additives.end(),
                               [id](const AdditiveProfile& profile) {
                                   return profile.id == id;
                               });

        if (it == _additives.end()) continue;

        QString field          = translationQuery.value("field"         ).toString();
        QString language       = translationQuery.value("language"      ).toString();
        QString definition     = translationQuery.value("definition"    ).toString();
        QString recommendation = translationQuery.value("recommendation").toString();
        QString measurement    = translationQuery.value("measurement"   ).toString();

        ComponentName* target = nullptr;
        if      (field == "name"          ) target = &it->name          ;
        else if (field == "type"          ) target = &it->type          ;
        else if (field == "comment"       ) target = &it->comment       ;
        else if (field == "recommendation") target = &it->recommendation;
        else if (field == "measurement"   ) target = &it->measurement   ;

        if(!target) continue;
        if      (language == "ru") target->ru = definition;
        else if (language == "en") target->en = definition;
    }
    return *this;
}

DatabaseManager &DatabaseManager::loadDyes()
{
    _dyes.clear();

    QSqlQuery query("SELECT * FROM dyes;");
    while (query.next()) {
        DyeProfile profile;
        // Id
        profile.id =  query.value("id").toInt();
        // INCI
        profile.inci = query.value("inci").toString();
        _dyes.append(profile);
    }

    QSqlQuery translationQuery("SELECT * FROM dye_translations;");
    while (translationQuery.next()) {
        qint32 id = translationQuery.value("id").toInt();
        auto it = std::find_if(_dyes.begin(), _dyes.end(),
                               [id](const DyeProfile &profile) {
                                   return profile.id == id;
                               });
        if (it == _dyes.end()) continue;

        QString field          = translationQuery.value("field"         ).toString();
        QString language       = translationQuery.value("language"      ).toString();
        QString definition     = translationQuery.value("definition"    ).toString();

        ComponentName* target = nullptr;
        if      (field == "name"          ) target = &it->name          ;
        else if (field == "type"          ) target = &it->type          ;
        else if (field == "comment"       ) target = &it->comment       ;

        if(!target) continue;
        if      (language == "ru") target->ru = definition;
        else if (language == "en") target->en = definition;
    }
    return *this;
}

DatabaseManager &DatabaseManager::loadAromas()
{
    _aromas.clear();

    QSqlQuery query("SELECT * FROM aromas;");
    while (query.next()){
        AromaProfile profile;
        profile.id   = query.value("id"  ).toInt   ();
        profile.inci = query.value("inci").toString();
        _aromas.append(profile);
    }

    QSqlQuery translationQuery("SELECT * FROM aroma_translations;");
    while (translationQuery.next()) {
        qint32 id = translationQuery.value("id").toInt();
        auto it = std::find_if(_aromas.begin(), _aromas.end(),
                               [id](const AromaProfile &profile) {
                                   return profile.id == id;
                               });
        if (it == _aromas.end()) continue;

        QString field          = translationQuery.value("field"         ).toString();
        QString language       = translationQuery.value("language"      ).toString();
        QString definition     = translationQuery.value("definition"    ).toString();

        ComponentName* target = nullptr;
        if      (field == "name"          ) target = &it->name          ;
        else if (field == "type"          ) target = &it->type          ;
        else if (field == "comment"       ) target = &it->comment       ;

        if(!target) continue;
        if      (language == "ru") target->ru = definition;
        else if (language == "en") target->en = definition;
    }

    return *this;
}

DatabaseManager &DatabaseManager::loadLiquids()
{
    _liquids.clear();
    QSqlQuery query("SELECT * FROM liquids;");
    while (query.next()){
        LiquidProfile profile;
        profile.id   = query.value("id"  ).toInt   ();
        profile.inci = query.value("inci").toString();
        _liquids.append(profile);
    }

    QSqlQuery translationQuery("SELECT * FROM liquid_translations;");
    while (translationQuery.next()) {
        qint32 id = translationQuery.value("id").toInt();
        auto it = std::find_if(_liquids.begin(), _liquids.end(),
                               [id](const LiquidProfile &profile) {
                                   return profile.id == id;
                               });
        if (it == _liquids.end()) continue;

        QString field          = translationQuery.value("field"         ).toString();
        QString language       = translationQuery.value("language"      ).toString();
        QString definition     = translationQuery.value("definition"    ).toString();

        ComponentName* target = nullptr;
        if      (field == "name"          ) target = &it->name          ;
        else if (field == "comment"       ) target = &it->comment       ;

        if(!target) continue;
        if      (language == "ru") target->ru = definition;
        else if (language == "en") target->en = definition;
    }
    return *this;
}

LipidContainer    &DatabaseManager::lipids   () { return _lipids;    }
AcidContainer     &DatabaseManager::acids    () { return _acids;     }
AdditiveContainer &DatabaseManager::additives() { return _additives; }
DyeContainer      &DatabaseManager::dyes     () { return _dyes;      }
AromaContainer    &DatabaseManager::aromas   () { return _aromas;    }
LiquidContainer   &DatabaseManager::liquids  () { return _liquids;   }



