#include "FloatingPoint.hpp"

#include <math.h>
#include <algorithm>

FloatingPoint::FloatingPoint() {

}

int FloatingPoint::sign() {
    int retval = this->signBits().at(0) == '1' ? -1 : 1;
    return retval;
}

unsigned long FloatingPoint::exponent() {
    std::string bits = this->bitset.getExponentBits();
    std::reverse(bits.begin(), bits.end());

    unsigned long exponent = 0;
    for (int i=0; i<bits.length(); i++) {
        if (bits.at(i) == '1') {
            exponent += pow(2, i);
        }
    }
    return exponent;
}

std::string FloatingPoint::bits() {
    return this->bitset.getAllBits();
}

std::string FloatingPoint::mantisaBits() {
    return this->bitset.getMantisaBits();
}

std::string FloatingPoint::exponentBits() {
    return this->bitset.getExponentBits();
}

std::string FloatingPoint::signBits() {
    return this->bitset.getSignBits();
}