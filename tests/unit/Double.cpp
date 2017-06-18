#include "gtest/gtest.h"

#include "classes/Double.hpp"

TEST(Double, test_bits_equals) {
    Double point(3.14);

    std::string imploded = point.signBits() + point.exponentBits() + point.mantisaBits();
    std::string all = point.bits();
    EXPECT_EQ(0, all.compare(imploded));
}

TEST(Double, test_values_equals) {
    Double point(3.14);

    EXPECT_FLOAT_EQ(point.computedValue(), 3.14);
}

TEST(Double, test_zero) {
    Double point(0.0);

    EXPECT_EQ(1, point.sign());
    EXPECT_EQ(0, point.exponent());
    EXPECT_DOUBLE_EQ(1.0, point.mantisa());
}

TEST(Double, test_sign_negative) {
    Double point(-1.5);

    EXPECT_EQ(-1, point.sign());
}

TEST(Double, test_sign_positive) {
    Double point(1.5);

    EXPECT_EQ(1, point.sign());
}

TEST(Double, test_exponent) {
    Double point(3.4);

    double exponent = 1024;
    EXPECT_EQ(exponent, point.exponent());
}

TEST(Double, test_mantisa) {
    Double point(3.4);

    double mantisa = 1.6999999999999999555910790149937383830547332763671875;
    EXPECT_DOUBLE_EQ(mantisa, point.mantisa());
}