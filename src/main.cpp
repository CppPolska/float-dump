#include <iostream>

#include "FloatingPoint.hpp"

/*
 * Sources:
 *
 * Calculator                       https://www.h-schmidt.net/FloatConverter/IEEE754.html
 * Knowledge                        https://www.doc.ic.ac.uk/~eedwards/compsys/float/
 * Mathematics (single precision)   https://en.wikipedia.org/wiki/Single-precision_floating-point_format
 * Mathematics (double precision)   https://en.wikipedia.org/wiki/Double-precision_floating-point_format
 */

int main() {
    FLOATING_TYPE f = -123.45;

    FloatingPoint dump(f);

    std::cout << "Dumping bits..." << std::endl;
    std::cout << "Full dump:\t\t\t" << dump.bits() << std::endl;
    std::cout << "Sign:\t\t\t\t" << dump.signBits() << std::endl;
    std::cout << "Exponent:\t\t\t" << dump.exponentBits() << std::endl;
    std::cout << "Mantisa:\t\t\t" << dump.mantisaBits() << std::endl;

    std::cout << std::endl;

    std::cout << "Dumping values..." << std::endl;
    std::cout << "Sign:\t\t\t\t" << dump.sign() << std::endl;
    std::cout << "Exponent:\t\t\t" << dump.exponent() << std::endl;

    std::cout.precision(34);
    std::cout << "Mantisa:\t\t\t" << dump.mantisa() << std::endl;

    std::cout.precision(34);
    std::cout << "Calculated value:\t" << dump.computedValue() << std::endl;
    return 0;
}