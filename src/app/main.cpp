#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include <qqml.h>

// #include "soap_core.h"
#include "irepository.h"
#include "database.h"

#include "lipid_model.h"
#include "acid_model.h"
#include "additive_model.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QString src = "F:\\Projects\\QT\\soap-calculator\\data\\repository.json";
    Database database(new IJsonRepository(src));

    LipidModel lipidModel = LipidModel();
    lipidModel.setModel(QVariant::fromValue(database.lipids()));
    AcidModel acidModel = AcidModel();
    acidModel.setModel(QVariant::fromValue(database.acids()));
    AdditiveModel additiveModel = AdditiveModel();
    additiveModel.setModel(QVariant::fromValue(database.additives()));

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("lipidModel", &lipidModel);
    engine.rootContext()->setContextProperty("acidModel", &acidModel);
    engine.rootContext()->setContextProperty("additiveModel", &additiveModel);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.loadFromModule("SoapCalculator", "Main");

    return app.exec();
}
