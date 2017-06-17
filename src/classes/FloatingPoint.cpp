#include "FloatingPoint.hpp"

#include <bitset>
#include <math.h>

FloatingPoint::FloatingPoint (FLOATING_TYPE value) {
    this->cast.value = value;
};

int FloatingPoint::sign () {
    return this->cast.parts.sign ? -1 : 1;
}

unsigned long FloatingPoint::exponent () {
    return this->cast.parts.exponent;
}

FLOATING_TYPE FloatingPoint::mantisa () {
    std::string mantisaBits = this->mantisaBits();

    FLOATING_TYPE mantisa = 0;
    for (size_t i=0; i<mantisaBits.size(); i++) {
        if (mantisaBits[i] == '1') {
            FLOATING_TYPE exponent = (i+1);
            mantisa += 1/pow(2, exponent);
        }
    }
    return 1.0+mantisa;
}

FLOATING_TYPE FloatingPoint::computedValue() {
    if (this->isZero()) {
        return 0.0;
    }
    return this->sign() * this->mantisa() * pow(2, this->exponent()-EXPONENT_BIAS);
}

std::string FloatingPoint::bits () {
    std::bitset<sizeof(FLOATING_TYPE)*8> bits(*reinterpret_cast<unsigned long*>(&(this->cast.value)));
    return bits.to_string();
}

std::string FloatingPoint::mantisaBits () {
    unsigned long value = this->cast.parts.mantisa;
    std::bitset<MANTISA_BITS> bits(value);
    return bits.to_string();
}

std::string FloatingPoint::exponentBits () {
    unsigned long value = this->cast.parts.exponent;
    std::bitset<EXPONENT_BITS> bits(value);
    return bits.to_string();
}

std::string FloatingPoint::signBits () {
    unsigned long value = this->cast.parts.sign;
    std::bitset<SIGN_BITS> bits(value);
    return bits.to_string();
}

bool FloatingPoint::isZero() {
    return this->cast.parts.sign == 0 && this->cast.parts.exponent == 0 && this->cast.parts.mantisa == 0;
}