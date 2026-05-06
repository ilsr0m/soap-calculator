#include "irepository.h"
#include "json_loader.h"

IJsonRepository::IJsonRepository(QString source) : IRepository()
{
    _source = std::move(source);
}

IRepository& IJsonRepository::load()
{
    QJsonDocument doc = JsonLoader().load(_source).document();

    if(doc.isObject()) {
        QJsonObject obj = doc.object();

        QJsonArray lipids =  obj.value("lipids").toArray();
        for(const auto& v : lipids) {
            _repository.lipids.insert(v.toObject().value("id").toString(), toLipid(v));
        }

        QJsonArray acids =  obj.value("acids").toArray();
        for(const auto& v : acids) {
            _repository.acids.insert(v.toObject().value("id").toString(), toAcid(v));
        }

        QJsonArray additives =  obj.value("additives").toArray();
        for(const auto& v : additives) {
            _repository.additives.insert(v.toObject().value("id").toString(), toAdditive(v));
        }
    }

    return *this;
}

LipidProfile IJsonRepository::toLipid(const QJsonValue& val)
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

AcidProfile IJsonRepository::toAcid(const QJsonValue &val)
{
    AcidProfile profile;

    auto name = val.toObject().value("name");
    profile.name.en = name.toObject().value("en").toString();
    profile.name.ru = name.toObject().value("ru").toString();

    auto neutralization = val.toObject().value("neutralization");
    profile.neutralization.KOH = neutralization.toObject().value("KOH").toDouble();
    profile.neutralization.NaOH = neutralization.toObject().value("NaOH").toDouble();

    return profile;
}

AdditiveProfile IJsonRepository::toAdditive(const QJsonValue &val)
{
    AdditiveProfile profile;
    auto name = val.toObject().value("name");
    profile.name.en = name.toObject().value("en").toString();
    profile.name.ru = name.toObject().value("ru").toString();
    return profile;
}



