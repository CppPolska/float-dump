#pragma once

#include <string>
#include "classes/Bits.hpp"

class FloatingPoint {

public:

    FloatingPoint();

    std::string bits();
    std::string mantisaBits();
    std::string exponentBits();
    std::string signBits();

    int sign();
    unsigned long exponent();

protected:

    Bits bitset;

};
