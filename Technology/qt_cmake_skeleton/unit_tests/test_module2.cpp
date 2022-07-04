#include "gtest/gtest.h"

#include <cmath>
#include "module2.h"

TEST(Module2TestSuite, TestAdd) {
    double result = 0;

    Module2Class module2;
    result = module2.AddDouble(2.25176, 3.45689);
    result = fabs(result - 5.7086);

    EXPECT_TRUE(result <= 1e-4);
}

TEST(Module2TestSuite, TestMultiply) {
    double result = 0;

    Module2Class module2;
    result = module2.MultiplyDouble(12.55326, -71.24867);
    result = fabs(result - (-894.4030));

    EXPECT_TRUE(result <= 1e-4);
}
