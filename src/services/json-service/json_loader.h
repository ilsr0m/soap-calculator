#ifndef JSON_LOADER_H
#define JSON_LOADER_H

#include <QJsonDocument>
#include <QFile>

class JsonLoader
{
public:
    JsonLoader();
    JsonLoader& load(QString sourse);
    inline QJsonDocument document() { return _document; }

private:
    QJsonDocument _document;
};

#endif // JSON_LOADER_H
