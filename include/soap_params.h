#ifndef SOAP_PARAMS_H
#define SOAP_PARAMS_H

#include <QVector>
#include <QString>

// Input - Входные параметры
struct ComponentInput {
    QString id; // Название компонента
    qreal percent; // Процент от общей массы
};

struct PercentParameters {
    qreal KOH = 0;       // Процент гидроксида калия
    qreal NaOH = 100;    // Процент гидроксида натрия
    qreal water = 33;    // Процент воды от общей массы масел
    qreal superfat = 5;  // Пережир
};

struct RecipeInput {
    qreal totalLipidMass;               // общая масса липидов
    QVector<ComponentInput> lipids;     // липиды
    QVector<ComponentInput> additives;  // дополнительные ингредиенты
    PercentParameters percents;
};

// Output - Выходные параметры
struct ComponentOutput {
    QString id;
    qreal mass = 0;
};

struct MassParameters {
    qreal water = 0; // Вода в граммах
    qreal NaOH = 0;  // Гидроксид натрия в граммах
    qreal KOH= 0;    // Гидроксид калия в граммах
};

struct RecipeOutput {
    QVector<ComponentOutput> lipids;
    QVector<ComponentOutput> additives; // дополнительные ингредиенты
    MassParameters masses;
};

// Lipid data
// Йодовое число
struct Iodine {
    qreal min = 0;
    qreal max = 0;
    qreal avg = 0;
};

struct Sap {
    qreal NaOH = 0;
    qreal KOH = 0;
};

struct ComponentName {
    QString en;
    QString ru;
};

// Профиль каждого липида
struct LipidProfile {
    ComponentName name;
    Sap sap;        // сапонификационное число
    Iodine iodine;  // йодовое значение
};

struct AdditiveProfile {
    ComponentName name;
    qreal usagePercent = 0;
};

struct AcidProfile {
    ComponentName name;
    Sap neutralization;
    qreal usagePercent = 0;
};

#endif // SOAP-DATA_H
