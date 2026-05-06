#ifndef IREPOSITORY_H
#define IREPOSITORY_H

#include "soap_params.h"

#include <QJsonObject>
#include <QJsonArray>

class IRepository
{
public:
    virtual ~IRepository() = default;
    virtual QMap<QString, LipidProfile> load() = 0;
};

class IJsonRepository : public IRepository {
public:
    IJsonRepository(QString source);
    virtual QMap<QString, LipidProfile> load() override;
private:
    LipidProfile processObject(const QJsonValue& val);
    QString _source;
};

#endif // IREPOSITORY_H
