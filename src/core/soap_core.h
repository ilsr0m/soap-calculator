#ifndef SOAP_CORE_H
#define SOAP_CORE_H

#include <QObject>
#include <QMap>

#include "soap_params.h"
#include "irepository.h"

class SoapCore : public QObject
{
Q_OBJECT
public:
    explicit SoapCore(IRepository *repository, QObject* parent = nullptr);

    inline SoapCore& setInput(const RecipeInput &input) { _input = input; return *this; }
    inline RecipeOutput output() const { return _output; }

    Q_INVOKABLE void compute();

private:

    inline Sap getSap(const QString& id) {
        return _lipidProfiles.value(id).sap;
    }

    void computeLipids();
    void computeWater();
    void computeLye();

    RecipeInput _input;
    RecipeOutput _output;

    QMap<QString, LipidProfile> _lipidProfiles;
};

#endif // SOAP_CORE_H
