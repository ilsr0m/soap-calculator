#ifndef SOAP_PROFILES_H
#define SOAP_PROFILES_H

/**
 * @file SoapProfiles.h
 * @brief Contains profile structures for soap recipe components.
 *
 * This file defines data profiles for different soap-making components:
 * lipids, acids, additives, aromas and dyes.
 *
 * Profiles describe reference data stored in the database and should not
 * contain recipe-specific input values such as selected amount or percentage.
 */

#include <QVector>
#include <QString>
#include <QMetaType>

/**
 * @brief Localized text value.
 *
 * Stores the same text in multiple languages and provides
 * a helper function for retrieving the value according to
 * the selected language.
 */
struct ComponentName {
    QString en; ///< English text.
    QString ru; ///< Russian text.

    /**
     * @brief Returns the text for the specified language.
     *
     * If the requested language is not available,
     * the English text is returned.
     *
     * @param lang Language code (for example "en" or "ru").
     * @return Localized text.
     */
    QString value(const QString& lang) const {
        if (lang == "ru")
            return ru;
        if (lang == "en")
            return en;
        return en;
    }
};

/**
 * @brief Saponification or neutralization values.
 *
 * Stores coefficients for sodium hydroxide and potassium hydroxide.
 */
struct Sap {
    qreal sodium    = 0; ///< SAP value for sodium hydroxide (NaOH).
    qreal potassium = 0; ///< SAP value for potassium hydroxide (KOH).
};

/**
 * @brief Calculated soap properties produced by a lipid.
 *
 * Contains common soap quality indicators used for recipe analysis.
 */
struct LipidProperties {
    qreal hardness     = 0; ///< Hardness index.
    qreal cleansing    = 0; ///< Cleansing index.
    qreal conditioning = 0; ///< Conditioning index.
    qreal bubbly       = 0; ///< Bubbly lather index.
    qreal creamy       = 0; ///< Creamy lather index.
    qreal iodine       = 0; ///< Iodine value.
};

/**
 * @brief Fatty acid composition of a lipid.
 *
 * Values are usually stored as percentages of the total fatty acid profile.
 */
struct FattyComposition {
    qreal lauric     = 0; ///< Lauric acid (%).
    qreal myristic   = 0; ///< Myristic acid (%).
    qreal palmitic   = 0; ///< Palmitic acid (%).
    qreal stearic    = 0; ///< Stearic acid (%).
    qreal ricinoleic = 0; ///< Ricinoleic acid (%).
    qreal oleic      = 0; ///< Oleic acid (%).
    qreal linoleic   = 0; ///< Linoleic acid (%).
    qreal linolenic  = 0; ///< Linolenic acid (%).
    qreal others     = 0; ///< Sum of all remaining fatty acids.
};

/**
 * @brief Base profile data shared by all component profiles.
 *
 * Contains common fields such as database identifier, localized name
 * and localized comment.
 */
struct BaseProfile {
    qint32 id = -1;        ///< Unique database identifier.
    ComponentName name;    ///< Localized component name.
    ComponentName comment; ///< Additional localized description.
};

/**
 * @brief Reference profile for a lipid component.
 *
 * Describes oils, butters and fats used in soap recipes.
 * Contains SAP values, soap properties, fatty acid composition
 * and INCI names for sodium and potassium soaps.
 */
struct LipidProfile : public BaseProfile {
    ComponentName type;         ///< Lipid category (oil, butter, animal fat, etc.).
    Sap sap;                    ///< Saponification values.
    LipidProperties properties; ///< Soap quality properties.
    FattyComposition fatties;   ///< Fatty acid composition.

    QString inciSodium;         ///< INCI name for sodium soap.
    QString inciPotassium;      ///< INCI name for potassium soap.

    /**
    * @brief Compares profiles by database identifier.
    * @param other Profile to compare with.
    * @return True if both profiles have the same identifier.
    */
    bool operator==(const LipidProfile& other) const { return id == other.id; }
};

/**
 * @brief Reference profile for an acid component.
 *
 * Describes acids used in soap recipes and stores neutralization values
 * for sodium hydroxide and potassium hydroxide.
 */
struct AcidProfile : public BaseProfile {
    ComponentName recommendation; ///< Recommended usage.
    Sap neutralization;           ///< Neutralization values.

    QString inciSodium;           ///< Sodium salt INCI.
    QString inciPotassium;        ///< Potassium salt INCI.

    /**
    * @brief Compares profiles by database identifier.
    * @param other Profile to compare with.
    * @return True if both profiles have the same identifier.
    */
    bool operator==(const AcidProfile& other) const { return id == other.id; }
};

/**
 * @brief Reference profile for an additive component.
 *
 * Describes non-lipid additives such as clays, salts, sugars,
 * proteins and other functional ingredients.
 */
struct AdditiveProfile : public BaseProfile {
    ComponentName type;           ///< Additive category.
    ComponentName recommendation; ///< Recommended dosage.
    ComponentName measurement;    ///< Measurement unit (g, ml, pcs, etc.).

    QString inci;                 ///< INCI name.

    /**
    * @brief Compares profiles by database identifier.
    * @param other Profile to compare with.
    * @return True if both profiles have the same identifier.
    */
    bool operator==(const AdditiveProfile& other) const { return id == other.id; }
};

/**
 * @brief Reference profile for an aroma component.
 *
 * Describes essential oils, fragrance oils and other aromatic ingredients.
 */
struct AromaProfile : public BaseProfile {
    ComponentName type; ///< Aroma category (essential oil, fragrance oil, etc.).
    QString inci;       ///< INCI name.

    /**
    * @brief Compares profiles by database identifier.
    * @param other Profile to compare with.
    * @return True if both profiles have the same identifier.
    */
    bool operator==(const AromaProfile& other) const { return id == other.id; }
};

/**
 * @brief Reference profile for a dye component.
 *
 * Describes colorants used in soap recipes, such as liquid dyes,
 * pigments, powders or mica colorants.
 */
struct DyeProfile : public BaseProfile {
    ComponentName type;        ///< Dye category (liquid, powder, mica, etc.).
    QString inci;              ///< INCI name.

    /**
    * @brief Compares profiles by database identifier.
    * @param other Profile to compare with.
    * @return True if both profiles have the same identifier.
    */
    bool operator==(const DyeProfile& other) const { return id == other.id; }
};

/**
 * @brief Represents a liquid profile.
 *
 * Stores information about a liquid ingredient, including its
 * International Nomenclature of Cosmetic Ingredients (INCI) name.
 */
struct LiquidProfile : public BaseProfile {
    QString inci; ///< INCI name.

    /**
    * @brief Compares profiles by database identifier.
    * @param other Profile to compare with.
    * @return True if both profiles have the same identifier.
    */
    bool operator==(const LiquidProfile& other) const { return id == other.id; }
};

using LipidContainer = QVector<LipidProfile>;
Q_DECLARE_METATYPE(LipidProfile)

using AcidContainer = QVector<AcidProfile>;
Q_DECLARE_METATYPE(AcidProfile)

using AdditiveContainer = QVector<AdditiveProfile>;
Q_DECLARE_METATYPE(AdditiveProfile)

using AromaContainer = QVector<AromaProfile>;
Q_DECLARE_METATYPE(AromaProfile)

using DyeContainer = QVector<DyeProfile>;
Q_DECLARE_METATYPE(DyeProfile)

using LiquidContainer = QVector<LiquidProfile>;
Q_DECLARE_METATYPE(LiquidProfile)

#endif // SOAPPROFILES_H
