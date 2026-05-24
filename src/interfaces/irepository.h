#ifndef IREPOSITORY_H
#define IREPOSITORY_H

#include "soap_params.h"

#include <QJsonObject>
#include <QJsonArray>

struct RepositoryEntities
{
    LipidContainer lipids;
    AcidContainer acids;
    AdditiveContainer additives;
};

class IRepository
{
public:
    virtual ~IRepository() = default;
    virtual void load() = 0;

    inline const RepositoryEntities& repository() const { return _repository; }

protected:
    RepositoryEntities _repository;
};

class IJsonRepository : public IRepository {
public:
    IJsonRepository(QString source);
    virtual void load() override;

private:
    LipidProfile    toLipid   (const QJsonValue& val);
    AcidProfile      toAcid    (const QJsonValue& val);
    AdditiveProfile  toAdditive(const QJsonValue& val);

    QString _source;
};

#endif // IREPOSITORY_H
