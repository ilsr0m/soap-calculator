#ifndef SOAPTYPES_H
#define SOAPTYPES_H

#include <QVector>
#include <QString>
#include <QMetaType>

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
 * @brief Properties of
 */
struct LipidProperties {
    qreal hardness = 0;
    qreal cleansing = 0;
    qreal conditioning = 0;
    qreal bubbly = 0;
    qreal creamy = 0;
    qreal iodine = 0;
};

struct Sap {
    qreal sodium = 0;
    qreal potassium = 0;
};

// Профиль каждого липида
struct LipidProfile {
    qint32 id;

    ComponentName type;
    ComponentName name;
    ComponentName comment;

    Sap sap; // сапонификационное число
    LipidProperties properties;

    QString inciSodium;
    QString inciPotassium;

    bool operator==(const LipidProfile& other) const { return id == other.id; }
};
using LipidContainer = QVector<LipidProfile>;
// using QLipidMap = QMap<QString, LipidProfile>;
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
// using QAcidMap = QMap<QString, AcidProfile>;
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
// using QAdditiveMap = QMap<QString, AdditiveProfile>;
Q_DECLARE_METATYPE(AdditiveProfile)

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
    qreal potassium = 0;       // Процент гидроксида калия
    qreal sodium = 100;    // Процент гидроксида натрия
    qreal water = 33;    // Процент воды от общей массы масел
    qreal superfat = 5;  // Пережир
    qreal additionalSuperfat = 0; // Дополнительный пережир (исп. в холодном способе)
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
    qreal KOH = 0;    // Гидроксид калия в граммах
    qreal additonalSuperfat = 0;
};

struct RecipeOutput {
    QVector<LipidOutput> lipids;
    QVector<AdditiveOutput> additives; // дополнительные ингредиенты
    QVector<AcidOutput> acids;     // дополнительные ингредиенты
    MassParameters baseMasses;
};



#endif // SOAP-DATA_H
