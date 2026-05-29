#ifndef SOAPCORE_H
#define SOAPCORE_H

#include "soap_params.h"

class SoapCore
{
public:
    static const RecipeOutput calculate(const RecipeInput &input);
};

#endif // SOAPCORE_H
