#pragma once

#include "FloatingPoint.hpp"
#include "classes/Bits.hpp"

class Double : public FloatingPoint {

public:

    Double(double value);

    double computedValue();
    double mantisa();

private:

    unsigned exponentBias = 1023;

};
