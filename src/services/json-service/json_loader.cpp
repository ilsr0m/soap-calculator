#include "json_loader.h"

JsonLoader::JsonLoader() {}

JsonLoader& JsonLoader::load(QString sourse)
{
    QFile jFile(sourse);

    if(!jFile.open(QIODevice::ReadOnly)){
        qWarning()<<"Can not open json file";
        return *this;
    }

    // Чтение файла
    QString data = jFile.readAll();
    jFile.close();

    // Преобразование данных в JsonDocument (По типу Document Object Model для HTML)
    _document = QJsonDocument::fromJson(data.toUtf8());
    return *this;
}
