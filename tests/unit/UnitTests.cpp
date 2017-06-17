#include "gtest/gtest.h"

#include "classes/FloatingPoint.hpp"

TEST(UnitTests, test_bits_equals) {
    FloatingPoint point(3.14);

    std::string imploded = point.signBits() + point.exponentBits() + point.mantisaBits();
    EXPECT_EQ(0, point.bits().compare(imploded));
}

TEST(UnitTests, test_values_equals) {
    FloatingPoint point(3.14);

    EXPECT_FLOAT_EQ(point.computedValue(), 3.14);
}

TEST(UnitTests, test_zero) {
    FloatingPoint point(0.0);

    EXPECT_EQ(1, point.sign());
    EXPECT_EQ(0, point.exponent());
    EXPECT_FLOAT_EQ(1.0, point.mantisa());
}

TEST(UnitTests, test_sign_negative) {
    FloatingPoint point(-1.5);

    EXPECT_EQ(-1, point.sign());
}

TEST(UnitTests, test_sign_positive) {
    FloatingPoint point(1.5);

    EXPECT_EQ(1, point.sign());
}

TEST(UnitTests, test_exponent) {
    FloatingPoint point(3.4);

    float exponent = 128;
    EXPECT_EQ(exponent, point.exponent());
}

TEST(UnitTests, test_mantisa) {
    FloatingPoint point(3.4);

    float mantisa = 1.7000000476837158;
    EXPECT_FLOAT_EQ(mantisa, point.mantisa());
}