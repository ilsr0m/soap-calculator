#ifndef SOAP_PARAMS_H
#define SOAP_PARAMS_H

#include <QVector>
#include <QString>

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

// ------------------------------- //
// Input - Входные параметры
struct AdditiveInput {
    AdditiveProfile profile;
    qreal percent; // Процент от общей массы
};

struct LipidInput {
    LipidProfile profile;
    qreal percent; // Процент от общей массы
};

struct AcidInput {
    AcidProfile profile;
    qreal percent; // Процент от общей массы
};

// --------------------------------- //
struct PercentParameters {
    qreal KOH = 0;       // Процент гидроксида калия
    qreal NaOH = 100;    // Процент гидроксида натрия
    qreal water = 33;    // Процент воды от общей массы масел
    qreal superfat = 5;  // Пережир
};

struct RecipeInput {
    qreal baseLipidMass;               // Общая масса липидов
    PercentParameters basePercents;    // Проценты базовых параметров

    QVector<LipidInput> lipids;         // липиды
    QVector<AdditiveInput> additives;   // дополнительные ингредиенты
    QVector<AcidInput> acids;           // кислоты
};

// ------------------------------------- //
// Output - Выходные параметры
struct AdditiveOutput {
    AdditiveProfile profile;
    qreal mass;
};

struct LipidOutput {
    LipidProfile profile;
    qreal mass;
};

struct AcidOutput {
    AcidProfile profile;
    qreal mass;
};


// ---------------- //
struct MassParameters {
    qreal water = 0; // Вода в граммах
    qreal NaOH = 0;  // Гидроксид натрия в граммах
    qreal KOH= 0;    // Гидроксид калия в граммах
};

struct RecipeOutput {
    QVector<LipidOutput> lipids;
    QVector<AdditiveOutput> additives; // дополнительные ингредиенты
    QVector<AcidOutput> acids;     // дополнительные ингредиенты
    MassParameters baseMasses;
};



#endif // SOAP-DATA_H
