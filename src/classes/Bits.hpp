#pragma once

#include <string>

class Bits {

public:

    Bits();
    Bits(float value);
    Bits(double value);

    std::string getMantisaBits();
    std::string getExponentBits();
    std::string getSignBits();
    std::string getAllBits();

    bool isZero();

private:

    std::string bits;

    unsigned mantisaBitsCount();
    unsigned exponentBitsCount();
    unsigned signBitsCount();

    bool isFloat = false;
    bool isDouble = false;

};
