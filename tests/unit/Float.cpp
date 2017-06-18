#include "gtest/gtest.h"

#include "classes/Float.hpp"

TEST(Float, test_bits_equals) {
    Float point(3.14);

    std::string imploded = point.signBits() + point.exponentBits() + point.mantisaBits();
    std::string all = point.bits();
    EXPECT_EQ(0, all.compare(imploded));
}

TEST(Float, test_values_equals) {
    Float point(3.14);

    EXPECT_FLOAT_EQ(point.computedValue(), 3.14);
}

TEST(Float, test_zero) {
    Float point(0.0);

    EXPECT_EQ(1, point.sign());
    EXPECT_EQ(0, point.exponent());
    EXPECT_FLOAT_EQ(1.0, point.mantisa());
}

TEST(Float, test_sign_negative) {
    Float point(-1.5);

    EXPECT_EQ(-1, point.sign());
}

TEST(Float, test_sign_positive) {
    Float point(1.5);

    EXPECT_EQ(1, point.sign());
}

TEST(Float, test_exponent) {
    Float point(3.4);

    float exponent = 128;
    EXPECT_EQ(exponent, point.exponent());
}

TEST(Float, test_mantisa) {
    Float point(3.4);

    float mantisa = 1.7000000476837158;
    EXPECT_FLOAT_EQ(mantisa, point.mantisa());
}