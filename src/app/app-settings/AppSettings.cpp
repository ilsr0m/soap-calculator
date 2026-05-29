#include "AppSettings.h"

AppSettings AppSettings::_settings;

AppSettings& AppSettings::instance() { return _settings; }

QString AppSettings::language() const { return _language; }

void AppSettings::setLanguage(const QString &language) {
    if (_language == language) return;
    _language = language;
    emit languageChanged();
}

AppSettings::AppSettings(QObject *parent) : QObject(parent) {}
