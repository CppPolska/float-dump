#include "Double.hpp"

#include <math.h>

Double::Double(double value) {
    Bits bits(value);
    this->bitset = bits;
}

double Double::mantisa() {
    std::string bits = this->mantisaBits();

    double mantisa = 1.0;
    for (size_t i=0; i<bits.size(); i++) {
        if (bits[i] == '1') {
            double exponent = (i+1);
            mantisa += 1/pow(2, exponent);
        }
    }
    return mantisa;
}

double Double::computedValue() {
    if (this->bitset.isZero()) {
        return 0.0;
    }
    return (this->sign() * this->mantisa() * pow(2, this->exponent() - this->exponentBias));
}