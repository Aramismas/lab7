
#ifndef __FACTORYTEST_HPP__
#define __FACTORYTEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "add.h"
#include "sub.h"
#include "mult.h"
#include "div.h"
#include "pow.h"
#include "rand.h"
#include "factoryBase.h"

TEST(FactoryTest, BasicAddition) {
    char* test_val[3];
    test_val[0] = "8";
    test_val[1] = "+";
    test_val[2] = "2";
    Factory* factory = new Factory();
    Base* conversion = factory->parse(test_val, 3);
    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "8.000000 + 2.000000");
    EXPECT_EQ(conversion->evaluate(), 10.000000);
}

TEST(FactoryTest, BasicMultiplication) {
    char* test_val[3];
    test_val[0] = "8";
    test_val[1] = "*";
    test_val[2] = "2";
    Factory* factory = new Factory();
    Base* conversion = factory->parse(test_val, 3);
    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "8.000000 * 2.000000");
    EXPECT_EQ(conversion->evaluate(), 16.000000);
}

TEST(FactoryTest, BasicSubtraction) {
    char* test_val[3];
    test_val[0] = "8";
    test_val[1] = "-";
    test_val[2] = "2";
    Factory* factory = new Factory();
    Base* conversion = factory->parse(test_val, 3);
    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "8.000000 - 2.000000");
    EXPECT_EQ(conversion->evaluate(), 6.000000);
}

TEST(FactoryTest, BasicDivision) {
    char* test_val[3];
    test_val[0] = "8";
    test_val[1] = "/";
    test_val[2] = "2";
    Factory* factory = new Factory();
    Base* conversion = factory->parse(test_val, 3);
    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "8.000000 / 2.000000");
    EXPECT_EQ(conversion->evaluate(), 4.000000);
}

TEST(FactoryTest, BasicPower) {
    char* test_val[3];
    test_val[0] = "8";
    test_val[1] = "**";
    test_val[2] = "2";
    Factory* factory = new Factory();
    Base* conversion = factory->parse(test_val, 3);
    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "8.000000 ** 2.000000");
    EXPECT_EQ(conversion->evaluate(), 64.000000);
}

TEST(FactoryTest, ComboAddDivision) {
    char* test_val[3];
    test_val[0] = "8";
    test_val[1] = "/";
    test_val[2] = "2";
    test_val[1] = "+";
    test_val[2] = "5";
    Factory* factory = new Factory();
    Base* conversion = factory->parse(test_val, 3);
    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "8.000000 / 2.000000 + 5.000000");
    EXPECT_EQ(conversion->evaluate(), 9.000000);
} 

TEST(FactoryTest, ComboSubMult) {
    char* test_val[3];
    test_val[0] = "8";
    test_val[1] = "-";
    test_val[2] = "2";
    test_val[1] = "*";
    test_val[2] = "5";
    Factory* factory = new Factory();
    Base* conversion = factory->parse(test_val, 3);
    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "8.000000 - 2.000000 * 5.000000");
    EXPECT_EQ(conversion->evaluate(), 30.000000);
}

TEST(FactoryTest, InvalidInput) {
    char* test_val[3];
    test_val[0] = "8";
    test_val[1] = "(";
    test_val[2] = "2";
    Factory* factory = new Factory();
    Base* conversion = factory->parse(test_val, 3);
    EXPECT_EQ(conversion, nullptr);
}

#endif // factoryTest.hpp
