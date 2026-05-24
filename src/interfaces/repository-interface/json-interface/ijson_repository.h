#ifndef IJSON_REPOSITORY_H
#define IJSON_REPOSITORY_H

#include "irepository.h"

#include <QJsonObject>
#include <QJsonArray>

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
