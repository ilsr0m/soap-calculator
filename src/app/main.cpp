#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include <qqml.h>

#include "soap_core.h"
#include "irepository.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QString src = "F:\\Projects\\QT\\soap-calculator\\data\\lipids.json";
    IJsonRepository repository(src);
    SoapCore soapCore(&repository);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("soapCore", &soapCore);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("soap-calculator", "Main");

    return app.exec();
}
