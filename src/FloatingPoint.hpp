#pragma once

#include <string>

#define SIGN_BITS 1
#define FLOATING_SINGLE

#if defined(FLOATING_DOUBLE)
    #define FLOATING_TYPE double
    #define MANTISA_BITS 52
    #define EXPONENT_BITS 11
    #define EXPONENT_BIAS 1023
#elif defined(FLOATING_SINGLE)
    #define FLOATING_TYPE float
    #define MANTISA_BITS 23
    #define EXPONENT_BITS 8
    #define EXPONENT_BIAS 127
#endif

class FloatingPoint {

public:

    FloatingPoint (FLOATING_TYPE value);

    int sign();
    unsigned long exponent();
    FLOATING_TYPE mantisa();
    FLOATING_TYPE computedValue();

    std::string bits();
    std::string mantisaBits();
    std::string exponentBits();
    std::string signBits();

    FLOATING_TYPE add(FLOATING_TYPE, FLOATING_TYPE);
    FLOATING_TYPE sub(FLOATING_TYPE, FLOATING_TYPE);
    FLOATING_TYPE multi(FLOATING_TYPE, FLOATING_TYPE);
    FLOATING_TYPE div(FLOATING_TYPE, FLOATING_TYPE);

private:

    typedef union {
        FLOATING_TYPE value;
        struct {
            unsigned long mantisa : MANTISA_BITS;
            unsigned long exponent : EXPONENT_BITS;
            unsigned long sign : SIGN_BITS;
        } parts;
    } SinglePrecissionCast;

    SinglePrecissionCast cast;

    bool isZero();

};