#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include <qqml.h>

// #include "soap_core.h"
#include "ijson_repository.h"
#include "RepositoryManager.h"

#include "LipidModel.h"
#include "AcidModel.h"
#include "AdditiveModel.h"

#include "IngredientFilterProxyModel.h"

#include "AppSettings.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QString src = "F:\\Projects\\QT\\soap-calculator\\data\\repository.json";
    RepositoryManager database(new IJsonRepository(src));

    // Инициализация модели - липиды
    LipidModel lipidModel = LipidModel();
    lipidModel.setModel(QVariant::fromValue(database.lipids()));   
    IngredientFilterProxyModel lipidProxyModel;
    lipidProxyModel.setSourceModel(&lipidModel);
    lipidProxyModel.sort(0);

    // Инициализация модели - кислоты
    AcidModel acidModel = AcidModel();
    acidModel.setModel(QVariant::fromValue(database.acids()));
    IngredientFilterProxyModel acidProxyModel;
    acidProxyModel.setSourceModel(&acidModel);
    acidProxyModel.sort(0);

    // Инициализация модели -  дополнительные игредиенты
    AdditiveModel additiveModel = AdditiveModel();
    additiveModel.setModel(QVariant::fromValue(database.additives()));
    IngredientFilterProxyModel additiveProxyModel;
    additiveProxyModel.setSourceModel(&additiveModel);
    additiveProxyModel.sort(0);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("appSettings", &AppSettings::instance());
    engine.rootContext()->setContextProperty("lipidProxyModel"   , &lipidProxyModel   );
    engine.rootContext()->setContextProperty("acidProxyModel"    , &acidProxyModel    );
    engine.rootContext()->setContextProperty("additiveProxyModel", &additiveProxyModel);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.loadFromModule("SoapCalculator", "Main");

    return app.exec();
}
