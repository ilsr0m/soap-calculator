#ifndef JSON_MANAGER_H
#define JSON_MANAGER_H

#include <QJsonDocument>
#include <QFile>

/**
 * @brief JSON document manager.
 *
 * Provides methods for loading and accessing JSON data.
 */
class JsonManager
{
public:
    JsonManager();

    /**
    * @brief Loads a JSON document from the specified file path.
    *
    * @param source Path to the JSON file.
    * @return Reference to the JsonManager object.
    */
    JsonManager& load(const QString& source);

    /**
    * @brief Returns the JSON document.
    *
    * @return Const reference to the QJsonDocument object.
    */
    inline const QJsonDocument& document() const { return _document; }

private:
    QJsonDocument _document;
};

#endif // JSON_MANAGER_H
