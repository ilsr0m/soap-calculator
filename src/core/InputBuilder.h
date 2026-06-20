#ifndef INPUTBUILDER_H
#define INPUTBUILDER_H

#include "SoapTypes.h"

class InputBuilder
{
public:
    InputBuilder();

    inline InputBuilder& withTotalMass(const double value) {
        _input.baseLipidMass = value;
        return *this;
    }

    inline InputBuilder& withSuperfat(const double value) {
        _input.basePercents.superfat = value;
        return *this;
    }

    inline InputBuilder& withAdditionalSuperfat(const double value) {
        _input.basePercents.additionalSuperfat = value;
        return *this;
    }

    inline InputBuilder& withWater(const double value) {
        _input.basePercents.baseLiquid = value;
        return *this;
    }

    inline InputBuilder& withSodium(const double value) {
        _input.basePercents.sodium = value;
        return *this;
    }

    inline InputBuilder& withPotassium(const double value) {
        _input.basePercents.potassium = value;
        return *this;
    }

    // Название компонента
    inline InputBuilder& addLipid(const LipidProfile& profile, const qreal percent) {
        _input.lipids.append({profile, percent});
        return *this;
    }

    inline InputBuilder& addAdditive(const AdditiveProfile& profile, const qreal percent) {
        _input.additives.append({profile, percent});
        return *this;
    }

    inline InputBuilder& addAcid(const AcidProfile& profile, const qreal percent) {
        _input.acids.append({profile, percent});
        return *this;
    }

    inline const RecipeInput& build() const{ return _input; }

private:
    RecipeInput _input;
};

#endif // INPUTBUILDER_H
