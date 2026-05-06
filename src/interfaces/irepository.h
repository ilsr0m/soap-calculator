#ifndef IREPOSITORY_H
#define IREPOSITORY_H

#include "soap_params.h"

#include <QJsonObject>
#include <QJsonArray>

struct Repository
{
    QMap<QString, LipidProfile> lipids;
    QMap<QString, AcidProfile> acids;
    QMap<QString, AdditiveProfile> additives;
};

class IRepository
{
public:
    virtual ~IRepository() = default;
    virtual const IRepository& load() = 0;

    inline const Repository& repository() const { return _repository; }

protected:
    Repository _repository;
};

class IJsonRepository : public IRepository {
public:
    IJsonRepository(QString source);
    virtual const IRepository& load() override;

private:
    LipidProfile toLipid(const QJsonValue& val);
    AcidProfile toAcid(const QJsonValue& val);
    AdditiveProfile toAdditive(const QJsonValue& val);

    QString _source;
};

#endif // IREPOSITORY_H
