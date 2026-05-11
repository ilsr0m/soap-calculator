#ifndef SOAP_CORE_H
#define SOAP_CORE_H

#include "soap_params.h"

class SoapCore
{
public:
    static const RecipeOutput calculate(const RecipeInput &input);
};

#endif // SOAP_CORE_H
