#pragma once

#include "FloatingPoint.hpp"
#include "classes/Bits.hpp"

class Float : public FloatingPoint {

public:

    Float(float value);

    float computedValue();
    float mantisa();

private:

    unsigned exponentBias = 127;

};
