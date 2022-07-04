#include "gtest/gtest.h"

#include "module1.h"

TEST(Module1TestSuite, TestAdd) {
    int result = 0;

    Module1Class module1;
    result = module1.AddInt(2, 3);

    EXPECT_EQ(result, 5);
}

TEST(Module1TestSuite, TestMultiply) {
    int result = 0;

    Module1Class module1;
    result = module1.MultiplyInt(2, 3);

    EXPECT_EQ(result, 6);
}
