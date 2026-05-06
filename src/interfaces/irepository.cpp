#include "irepository.h"
#include "json_loader.h"

IJsonRepository::IJsonRepository(QString source)
{
    _source = std::move(source);
}

QMap<QString, LipidProfile> IJsonRepository::load()
{
    QMap<QString, LipidProfile> profiles;

    QJsonDocument doc = JsonLoader().load(_source).document();
    if(doc.isArray()) {
        QJsonArray jsonArray = doc.array();
        for(const auto& ar : jsonArray)
            profiles.insert(ar.toObject().value("id").toString(), processObject(ar));
    }
    return profiles;
}

LipidProfile IJsonRepository::processObject(const QJsonValue& val)
{
    LipidProfile profile;

    auto name = val.toObject().value("name");
    profile.name.en = name.toObject().value("en").toString();
    profile.name.ru = name.toObject().value("ru").toString();

    auto sap = val.toObject().value("sap");
    profile.sap.KOH = sap.toObject().value("KOH").toDouble();
    profile.sap.NaOH = sap.toObject().value("NaOH").toDouble();

    auto iodine = val.toObject().value("iodine");
    profile.iodine.max = iodine.toObject().value("max").toDouble();
    profile.iodine.min = iodine.toObject().value("min").toDouble();
    profile.iodine.avg = iodine.toObject().value("avg").toDouble();

    return profile;
}
