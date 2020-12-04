
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
    char* test_val[4];
    test_val[0] = "./calculator";
    test_val[1] = "8";
    test_val[2] = "+";
    test_val[3] = "2";
    Factory* factory = new Factory();
    Base* conversion = factory->parse(test_val, 4);
    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "8.000000 + 2.000000");
    EXPECT_EQ(conversion->evaluate(), 10.000000);
}

TEST(FactoryTest, BasicMultiplication) {
    char* test_val[4];
    test_val[0] = "./calculator";
    test_val[1] = "6";
    test_val[2] = "*";
    test_val[3] = "3";
    Factory* factory = new Factory();
    Base* conversion = factory->parse(test_val, 4);
    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "6.000000 * 3.000000");
    EXPECT_EQ(conversion->evaluate(), 18.000000);
}

TEST(FactoryTest, BasicSubtraction) {
    char* test_val[4];
    test_val[0] = "./calculator";
    test_val[1] = "12";
    test_val[2] = "-";
    test_val[3] = "2";
    Factory* factory = new Factory();
    Base* conversion = factory->parse(test_val, 4);
    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "12.000000 - 2.000000");
    EXPECT_EQ(conversion->evaluate(), 10.000000);
}

TEST(FactoryTest, BasicDivision) {
    char* test_val[4];
    test_val[0] = "./calculator";
    test_val[1] = "4";
    test_val[2] = "/";
    test_val[3] = "2";
    Factory* factory = new Factory();
    Base* conversion = factory->parse(test_val, 4);
    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "4.000000 / 2.000000");
    EXPECT_EQ(conversion->evaluate(), 2.000000);
}

TEST(FactoryTest, BasicPower) {
    char* test_val[5];
    test_val[0] = "./calculator";
    test_val[1] = "8";
    test_val[2] = "*";
    test_val[3] = "*";
    test_val[4] = "2";
    Factory* factory = new Factory();
    Base* conversion = factory->parse(test_val, 5);
    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "8.000000 ** 2.000000");
    EXPECT_EQ(conversion->evaluate(), 64.000000);
}

TEST(FactoryTest, ComboAddDivision) {
    char* test_val[6];
    test_val[0] = "./calculator";
    test_val[1] = "8";
    test_val[2] = "/";
    test_val[3] = "2";
    test_val[4] = "+";
    test_val[5] = "5";
    Factory* factory = new Factory();
    Base* conversion = factory->parse(test_val, 6);
    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "8.000000 / 2.000000 + 5.000000");
    EXPECT_EQ(conversion->evaluate(), 9.000000);
} 

TEST(FactoryTest, ComboSubMult) {
    char* test_val[6];
    test_val[0] = "./calculator";
    test_val[1] = "7";
    test_val[2] = "-";
    test_val[3] = "2";
    test_val[4] = "*";
    test_val[5] = "4";
    Factory* factory = new Factory();
    Base* conversion = factory->parse(test_val, 6);
    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "7.000000 - 2.000000 * 4.000000");
    EXPECT_EQ(conversion->evaluate(), 20.000000);
}

TEST(FactoryTest, ComboDoubleSubMult) {
    char* test_val[6];
    test_val[0] = "./calculator";
    test_val[1] = "13";
    test_val[2] = "-";
    test_val[3] = "2";
    test_val[4] = "*";
    test_val[5] = "3";
    Factory* factory = new Factory();
    Base* conversion = factory->parse(test_val, 6);
    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "13.000000 - 2.000000 * 3.000000");
    EXPECT_EQ(conversion->evaluate(), 33.000000);
}

TEST(FactoryTest, InvalidInput1) {
    char* test_val[4];
    test_val[0] = "./calculator";
    test_val[1] = "8";
    test_val[2] = "(";
    test_val[3] = "2";
    Factory* factory = new Factory();
    Base* conversion = factory->parse(test_val, 4);
    EXPECT_EQ(conversion, nullptr);
}

TEST(FactoryTest, InvalidInput2) {
    char* test_val[4];
    test_val[0] = "./calculator";
    test_val[1] = "2";
    test_val[2] = "*";
    test_val[3] = "d";
    Factory* factory = new Factory();
    Base* conversion = factory->parse(test_val, 4);
    EXPECT_EQ(conversion, nullptr);
}
#endif // factoryTest.hpp
