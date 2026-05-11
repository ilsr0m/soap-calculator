#include "soap_core.h"

const RecipeOutput SoapCore::calculate(const RecipeInput &input)
{
    RecipeOutput output;

    // Расчет массы воды
    // Сколько-то там процентов от общей массы липидов
    output.baseMasses.water = input.baseLipidMass * (input.basePercents.water / 100.00);

    // Расчет массы липидов
    for(const LipidInput& lipidIn : input.lipids) {
        LipidOutput lipidOut;
        lipidOut.profile = lipidIn.profile;
        // Расчет массы каждого липида
        lipidOut.mass = input.baseLipidMass * (lipidIn.percent / 100.00);
        output.lipids.append(lipidOut);
    }

    // Расчет массы кислот
    for(const AcidInput& acidIn : input.acids) {
        AcidOutput acidOut;
        acidOut.profile = acidIn.profile;
        // Расчет массы каждого липида
        acidOut.mass = input.baseLipidMass * (acidIn.percent / 100.00);
        output.acids.append(acidOut);
    }

    // Расчет массы щелочей
    const qreal superfatFactor = 1 - (input.basePercents.superfat / 100.0);
    qreal NaOHMassForLipids = 0;
    qreal NaOHPercent = input.basePercents.NaOH / 100.0;
    qreal KOHMassForLipids = 0;
    qreal KOHPercent = input.basePercents.KOH / 100.0;

    for(const LipidOutput& lipidOut : output.lipids){
        NaOHMassForLipids += lipidOut.profile.sap.NaOH * lipidOut.mass;
        KOHMassForLipids  += lipidOut.profile.sap.KOH  * lipidOut.mass;
    }

    output.baseMasses.NaOH = NaOHMassForLipids * NaOHPercent * superfatFactor;
    output.baseMasses.KOH  = KOHMassForLipids  * KOHPercent  * superfatFactor;

    // необходимо учесть коэффициенты нейтрализации
    for(const AcidOutput& acidOut : output.acids) {
        output.baseMasses.NaOH += acidOut.profile.neutralization.NaOH * acidOut.mass;
        output.baseMasses.KOH  += acidOut.profile.neutralization.KOH  * acidOut.mass;
    }

    // Расчет массы дополнительных игридиентов
    for(const AdditiveInput& additiveIn : input.additives) {
        AdditiveOutput acidOut;
        acidOut.profile = additiveIn.profile;
        // Расчет массы каждого липида
        acidOut.mass = input.baseLipidMass * (additiveIn.percent / 100.00);
        output.additives.append(acidOut);
    }

    return output;
}

