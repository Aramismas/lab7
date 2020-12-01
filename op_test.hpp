
#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "add.h"
#include "sub.h"
#include "mult.h"
#include "div.h"
#include "pow.h"
#include "rand.h"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpStringEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->stringify(), "8.000000");
}

TEST(OpTest, OpEvaluateZero) {
    Op* test = new Op(0);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpStringifyZero) {
    Op* test = new Op(0);
    EXPECT_EQ(test->stringify(), "0.000000");
}

TEST(AddTest, AddEvaluatePositive) {
    Op* test1 = new Op(2);
    Op* test2 = new Op(3);
    Add* test3 = new Add(test1, test2);
    EXPECT_EQ(test3->evaluate(), 5);
}

TEST(AddTest, AddEvaluateNegPos) {
    Op* test1 = new Op(-2);
    Op* test2 = new Op(3);
    Add* test3 = new Add(test1, test2);
    EXPECT_EQ(test3->evaluate(), 1);
}

TEST(AddTest, AddEvaluatePosNeg) {
    Op* test1 = new Op(2);
    Op* test2 = new Op(-3);
    Add* test3 = new Add(test1, test2);
    EXPECT_EQ(test3->evaluate(), -1);
}

TEST(AddTest, AddStringifyPositive) {
    Op* test1 = new Op(2);
    Op* test2 = new Op(3);
    Add* test3 = new Add(test1, test2);
    EXPECT_EQ(test3->stringify(), "2.000000 + 3.000000");
}

TEST(SubTest, SubStringifyPositiveNeg) {
    Op* test1 = new Op(2);
    Op* test2 = new Op(3);
    Sub* test3 = new Sub(test1, test2);
    EXPECT_EQ(test3->stringify(), "2.000000 - 3.000000");
}

TEST(MultTest, MultStringifyPositive) {
    Op* test1 = new Op(8);
    Op* test2 = new Op(7);
    Mult* test3 = new Mult(test1, test2);
    EXPECT_EQ(test3->stringify(), "8.000000 * 7.000000");
}

TEST(DivTest, DivStringifyPositive) {
    Op* test1 = new Op(4);
    Op* test2 = new Op(7);
    Div* test3 = new Div(test1, test2);
    EXPECT_EQ(test3->stringify(), "4.000000 / 7.000000");
}

TEST(PowTest, PowStringifyPositive) {
    Op* test1 = new Op(2);
    Op* test2 = new Op(3);
    Pow* test3 = new Pow(test1, test2);
    EXPECT_EQ(test3->stringify(), "2.000000 ** 3.000000");
}

TEST(AddTest, AddStringifyNegative) {
    Op* test1 = new Op(2);
    Op* test2 = new Op(-3);
    Add* test3 = new Add(test1, test2);
    EXPECT_EQ(test3->stringify(), "2.000000 + -3.000000");
}

TEST(SubTest, SubEvaluatePositive) {
    Op* test1 = new Op(3);
    Op* test2 = new Op(2);
    Sub* test3 = new Sub(test1, test2);
    EXPECT_EQ(test3->evaluate(), 1);
}

TEST(SubTest, SubEvaluateNegative) {
    Op* test1 = new Op(-3);
    Op* test2 = new Op(2);
    Sub* test3 = new Sub(test1, test2);
    EXPECT_EQ(test3->evaluate(), -5);
}

TEST(SubTest, SubStringifyPositive) {
    Op* test1 = new Op(3);
    Op* test2 = new Op(2);
    Sub* test3 = new Sub(test1, test2);
    EXPECT_EQ(test3->stringify(), "3.000000 - 2.000000");
}

TEST(SubTest, SubStringifyNegative) {
    Op* test1 = new Op(-2);
    Op* test2 = new Op(3);
    Sub* test3 = new Sub(test1, test2);
    EXPECT_EQ(test3->stringify(), "-2.000000 - 3.000000");
}
TEST(MultTest, CheckZero) {
    Op* test1 = new Op(8);
    Op* test2 = new Op(0);
    Mult* test3 = new Mult(test1, test2);
    EXPECT_EQ(test3->evaluate(), 0);
} 

TEST(MultTest, MultStringZero) {
    Op* test1 = new Op(8);
    Op* test2 = new Op(0);
    Mult* test3 = new Mult(test1, test2);
    EXPECT_EQ(test3->stringify(), "8.000000 * 0.000000");
}

TEST(MultTest, MultEvalPositive) {
    Op* test1 = new Op(8);
    Op* test2 = new Op(7);
    Mult* test3 = new Mult(test1, test2);
    EXPECT_EQ(test3->evaluate(), 56);
}

TEST(PowTest, PowEval) {
    Op* test1 = new Op(2);
    Op* test2 = new Op(3);
    Pow* test3 = new Pow(test1, test2);
    EXPECT_EQ(test3->evaluate(), 8);
}

TEST(PowTest, PowEvaltoTheZero) {
    Op* test1 = new Op(2);
    Op* test2 = new Op(0);
    Pow* test3 = new Pow(test1, test2);
    EXPECT_EQ(test3->evaluate(), 1);
}

TEST(PowTest, PowStringZero) {
    Op* test1 = new Op(2);
    Op* test2 = new Op(0);
    Pow* test3 = new Pow(test1, test2);
    EXPECT_EQ(test3->stringify(), "2.000000 ** 0.000000");
}

TEST(DivTest, DivEvalPositive) {
    Op* test1 = new Op(7);
    Op* test2 = new Op(7);
    Div* test3 = new Div(test1, test2);
    EXPECT_EQ(test3->evaluate(), 1);
}


TEST(DivTest, DivEvalNeg) {
    Op* test1 = new Op(7);
    Op* test2 = new Op(-7);
    Div* test3 = new Div(test1, test2);
    EXPECT_EQ(test3->evaluate(), -1);
}

TEST(DivTest, DivStringNeg) {
    Op* test1 = new Op(7);
    Op* test2 = new Op(-7);
    Div* test3 = new Div(test1, test2);
    EXPECT_EQ(test3->stringify(), "7.000000 / -7.000000");
}

TEST(RandTest, RandEval) {
    Rand* test = new Rand();
    double test2 = test->evaluate();
    EXPECT_EQ(test->evaluate(), test2);
}

TEST(RandTest, RandString) {
    Rand* test = new Rand();
    double test2 = test->evaluate();
    std::string test3 = std::to_string(test2);
    EXPECT_EQ(test->stringify(), test3);
}

TEST(ComboTest, ComboOneEval) {
    Op* test1 = new Op(12);
    Op* test2 = new Op(3);
    Op* test3 = new Op(2);
    Op* test4 = new Op(4);
    Div* test5 = new Div(test1, test2);
    Sub* test6 = new Sub(test5, test3); 
    Pow* test7 = new Pow(test6, test4);
    EXPECT_EQ(test7->evaluate(), 16);
} 

TEST(ComboTest, ComboOneString) {
    Op* test1 = new Op(12);
    Op* test2 = new Op(3);
    Op* test3 = new Op(2);
    Op* test4 = new Op(4);
    Div* test5 = new Div(test1, test2);
    Sub* test6 = new Sub(test5, test3);
    Pow* test7 = new Pow(test6, test4);
    EXPECT_EQ(test7->stringify(), "12.000000 / 3.000000 - 2.000000 ** 4.000000");
} 

TEST(ComboTest, ComboTwoEval) {
    Op* test1 = new Op(2);
    Op* test2 = new Op(3);
    Op* test3 = new Op(4);
    Op* test4 = new Op(2);
    Add* test5 = new Add(test1, test2);
    Mult* test6 = new Mult(test5, test3);
    Pow* test7 = new Pow(test6, test4);
    EXPECT_EQ(test7->evaluate(), 400);
}

TEST(ComboTest, ComboTwoString) {
    Op* test1 = new Op(2);
    Op* test2 = new Op(3);
    Op* test3 = new Op(4);
    Op* test4 = new Op(2);
    Add* test5 = new Add(test1, test2);
    Mult* test6 = new Mult(test5, test3);
    Pow* test7 = new Pow(test6, test4);
    EXPECT_EQ(test7->stringify(), "2.000000 + 3.000000 * 4.000000 ** 2.000000");
}
#endif //__OP_TEST_HPP__
