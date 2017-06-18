#include "Bits.hpp"

#include <bitset>

Bits::Bits() {

}

Bits::Bits(float value) {
    std::bitset<sizeof(float)*8> bits(*reinterpret_cast<unsigned long*>(&value));
    this->bits = bits.to_string();
    this->isFloat = true;
}

Bits::Bits(double value) {
    std::bitset<sizeof(double)*8> bits(*reinterpret_cast<unsigned long*>(&value));
    this->bits = bits.to_string();
    this->isDouble = true;
}

std::string Bits::getMantisaBits() {
    return this->bits.substr(this->signBitsCount()+this->exponentBitsCount(), this->mantisaBitsCount());
}

std::string Bits::getExponentBits() {
    return this->bits.substr(this->signBitsCount(), this->exponentBitsCount());
}

std::string Bits::getSignBits() {
    return this->bits.substr(0, this->signBitsCount());
}

unsigned Bits::mantisaBitsCount() {
    return this->isFloat ? 23 : 52;
}

unsigned Bits::exponentBitsCount() {
    return this->isFloat ? 8 : 11;
}

unsigned Bits::signBitsCount() {
    return 1;
}

std::string Bits::getAllBits() {
    return this->bits;
}

bool Bits::isZero() {
    for (int i=0; i<this->bits.length(); i++) {
        if (this->bits.at(i) == '1') {
            return false;
        }
    }
    return true;
}
