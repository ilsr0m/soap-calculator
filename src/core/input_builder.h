#ifndef INPUT_BUILDER_H
#define INPUT_BUILDER_H

#include "soap_params.h"

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
        _input.basePercents.water = value;
        return *this;
    }

    inline InputBuilder& withNaOH(const double value) {
        _input.basePercents.NaOH = value;
        return *this;
    }

    inline InputBuilder& withKOH(const double value) {
        _input.basePercents.KOH = value;
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

#endif // INPUT_BUILDER_H
