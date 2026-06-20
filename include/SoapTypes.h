#ifndef SOAPTYPES_H
#define SOAPTYPES_H

#include <QVector>
#include <QString>
#include <QMetaType>

// TODO: Добавить рекомендации к additives (например, рекомендуется добавлять до 2% и т. д.) (qreal)
// TODO: Добавить жирокислотный состав для липидов

struct ComponentName {
    QString en;
    QString ru;
    QString value(const QString& lang) const {
        if (lang == "ru")
            return ru;
        if (lang == "en")
            return en;
        return en;
    }
};

/**
 * @brief Свойства липида
 */
struct LipidProperties {
    qreal hardness = 0;
    qreal cleansing = 0;
    qreal conditioning = 0;
    qreal bubbly = 0;
    qreal creamy = 0;
    qreal iodine = 0;
};

/**
 * @brief Жирнокислотный состав
 */
struct FattyComposition {
    qreal lauric;   // Лауриновая кислота
    qreal myristic; // Миристиновая кислота
    qreal palmitic; // Пальмитиновая кислота
    qreal stearic; // Стеариновая кислота
    qreal ricinoleic; // Рицинолевая кислота
    qreal oleic; // Олеиновая кислота
    qreal linoleic; // Линолевая кислота
    qreal linolenic; // Линоленовая кислота
};

struct Sap {
    qreal sodium = 0;
    qreal potassium = 0;
};

// Профиль каждого липида
struct LipidProfile {
    qint32 id;

    ComponentName type; // Тип (Жидкое масло, Твердое масло, Животный жир и т. д.)
    ComponentName name; // Название липида
    ComponentName comment; // Комментарий к

    Sap sap; // сапонификационное число
    LipidProperties properties; // показатели свойств
    FattyComposition fatties; // состав жирных кислот

    QString inciSodium;
    QString inciPotassium;

    bool operator==(const LipidProfile& other) const { return id == other.id; }
};
using LipidContainer = QVector<LipidProfile>;
Q_DECLARE_METATYPE(LipidProfile)

struct AcidProfile {
    qint32 id;

    ComponentName name;
    ComponentName comment;

    Sap neutralization;

    QString inciSodium;
    QString inciPotassium;

    bool operator==(const AcidProfile& other) const { return id == other.id; }
};
using AcidContainer = QVector<AcidProfile>;
Q_DECLARE_METATYPE(AcidProfile)

struct AdditiveProfile {
    qint32 id;

    ComponentName type;
    ComponentName name;
    ComponentName comment;

    QString inci;
    bool operator==(const AdditiveProfile& other) const { return id == other.id; }
};
using AdditiveContainer = QVector<AdditiveProfile>;
Q_DECLARE_METATYPE(AdditiveProfile)

// Профиль базовых жидкостей
struct BaseLiquidProfile {
    qint32 id;
    ComponentName name;
    QString inci;
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
