#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QObject>
#include <QString>

class AppSettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString language READ language WRITE setLanguage NOTIFY languageChanged)

signals:
    void languageChanged();

public:

    static AppSettings& instance();

    QString language() const;
    void setLanguage(const QString& language);

private:
    explicit AppSettings(QObject* parent = nullptr);

    static AppSettings _settings;
    QString _language = "en";
};

#endif // APPSETTINGS_H
