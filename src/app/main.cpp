#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include <qqml.h>

// #include "soap_core.h"
#include "irepository.h"
#include "database.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QString src = "F:\\Projects\\QT\\soap-calculator\\data\\repository.json";
    Database database(new IJsonRepository(src));

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.loadFromModule("SoapCalculator", "Main");

    return app.exec();
}
