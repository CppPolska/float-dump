#include "Float.hpp"

#include <math.h>

Float::Float(float value) {
    Bits bits(value);
    this->bitset = bits;
}

float Float::mantisa() {
    std::string bits = this->mantisaBits();

    float mantisa = 1.0;
    for (size_t i=0; i<bits.size(); i++) {
        if (bits[i] == '1') {
            float exponent = (i+1);
            mantisa += 1/pow(2, exponent);
        }
    }
    return mantisa;
}

float Float::computedValue() {
    if (this->bitset.isZero()) {
        return 0.0;
    }
    return (float)(this->sign() * this->mantisa() * pow(2, this->exponent() - this->exponentBias));
}