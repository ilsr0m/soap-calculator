#ifndef SOAPTYPES_H
#define SOAPTYPES_H

#include <QVector>
#include <QString>
#include <QMetaType>
#include "SoapProfiles.h"

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
    qreal potassium = 0; // Процент гидроксида калия
    qreal sodium = 100; // Процент гидроксида натрия
    qreal baseLiquid = 33; // Процент воды от общей массы масел
    qreal superfat = 5; // Пережир
    qreal additionalSuperfat = 0; // Дополнительный пережир (исп. в холодном способе)
};

struct RecipeInput {
    qreal baseLipidMass; // Общая масса липидов
    PercentParameters basePercents; // Проценты базовых параметров

    QVector<LipidInput> lipids; // липиды
    QVector<AdditiveInput> additives; // дополнительные ингредиенты
    QVector<AcidInput> acids; // кислоты
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
    qreal baseLiquid = 0; // Вода в граммах
    qreal NaOH = 0;  // Гидроксид натрия в граммах
    qreal KOH = 0;    // Гидроксид калия в граммах
    qreal additonalSuperfat = 0;
};

struct RecipeOutput {
    QString title; // Название рецепта
    QString baseLiquidName; // Название жидкости
    QString comment; // Комментарий к рецепту

    QVector<LipidOutput> lipids;
    QVector<AdditiveOutput> additives; // дополнительные ингредиенты
    QVector<AcidOutput> acids;     // дополнительные ингредиенты

    PercentParameters basePercents; // Проценты базовых параметров
    MassParameters baseMasses;

    qreal ins; // Сбалансированность рецепта
};



#endif // SOAP-DATA_H
