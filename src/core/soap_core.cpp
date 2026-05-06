#include "soap_core.h"

SoapCore::SoapCore(IRepository *repository, QObject* parent)
    : QObject(parent)
{
    if(repository) {
        _lipidProfiles = repository->load();
    }
}

void SoapCore::compute()
{
    computeLipids();
    computeWater();
    computeLye();
}

void SoapCore::computeLipids()
{
    for(const ComponentInput& l : _input.lipids) {
        ComponentOutput out;
        out.id = l.id;
        out.mass = _input.totalLipidMass * (l.percent / 100.00);
        _output.lipids.append(out);
    }
}

void SoapCore::computeWater()
{
    _output.masses.water = _input.totalLipidMass * (_input.percents.water / 100.00);
}

void SoapCore::computeLye()
{
    qreal superfat = 1 - (_input.percents.superfat / 100.0);

    qreal NaOHMass = 0;
    qreal NaOHPercent = _input.percents.NaOH / 100.0;

    qreal KOHMass = 0;
    qreal KOHPercent = _input.percents.KOH / 100.0;

    for(const ComponentOutput& l : _output.lipids){
        Sap sap = getSap(l.id);
        NaOHMass += sap.NaOH * l.mass;
        KOHMass += sap.KOH * l.mass;
    }
    _output.masses.NaOH = NaOHMass * NaOHPercent * superfat;
    _output.masses.KOH = KOHMass * KOHPercent * superfat;
}
