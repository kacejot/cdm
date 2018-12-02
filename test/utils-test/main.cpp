#include <iostream>
#include <gtest/gtest.h>
#include "test_conditions.h"
#include "condition/and_condition.h"
#include "condition/or_condition.h"

TEST(ConditionTest, DummyConditionTest)
{
    OneCondition a;
    ASSERT_FALSE(a.match(2));
    ASSERT_TRUE(a.match(1));

    TwoCondition b;
    ASSERT_FALSE(b.match(1));
    ASSERT_TRUE(b.match(2));
}

TEST(ConditionTest, AndConditionTestWithLValue)
{
    OneCondition a;
    TwoCondition b;

    auto and_cond = a && b;

    ASSERT_FALSE(and_cond.match(0));
    ASSERT_FALSE(and_cond.match(1));
    ASSERT_FALSE(and_cond.match(2));
    ASSERT_FALSE(and_cond.match(3));
}

TEST(ConditionTest, AndConditionTestWithRValue)
{
    auto and_cond = OneCondition{} && TwoCondition{};

    ASSERT_FALSE(and_cond.match(0));
    ASSERT_FALSE(and_cond.match(1));
    ASSERT_FALSE(and_cond.match(2));
    ASSERT_FALSE(and_cond.match(3));
}

TEST(ConditionTest, AndConditionTestMixed)
{
    OneCondition a;
    TwoCondition b;

    auto and_cond = a && TwoCondition{};

    ASSERT_FALSE(and_cond.match(0));
    ASSERT_FALSE(and_cond.match(1));
    ASSERT_FALSE(and_cond.match(2));
    ASSERT_FALSE(and_cond.match(3));
}

TEST(ConditionTest, AndConditionTestSame)
{
    OneCondition a;

    auto and_cond = a && a && OneCondition{};

    ASSERT_FALSE(and_cond.match(0));
    ASSERT_TRUE(and_cond.match(1));
    ASSERT_FALSE(and_cond.match(2));
    ASSERT_FALSE(and_cond.match(3));
}

TEST(ConditionTest, OrConditionTestWithLValue)
{
    OneCondition a;
    TwoCondition b;

    auto or_cond = a || b;

    ASSERT_FALSE(or_cond.match(0));
    ASSERT_TRUE(or_cond.match(1));
    ASSERT_TRUE(or_cond.match(2));
    ASSERT_FALSE(or_cond.match(3));
}

TEST(ConditionTest, OrConditionTestWithRValue)
{
    auto or_cond = OneCondition{} || TwoCondition{};

    ASSERT_FALSE(or_cond.match(0));
    ASSERT_TRUE(or_cond.match(1));
    ASSERT_TRUE(or_cond.match(2));
    ASSERT_FALSE(or_cond.match(3));
}

TEST(ConditionTest, OrConditionTestMixed)
{
    OneCondition a;
    TwoCondition b;

    auto or_cond = a || TwoCondition{};

    ASSERT_FALSE(or_cond.match(0));
    ASSERT_TRUE(or_cond.match(1));
    ASSERT_TRUE(or_cond.match(2));
    ASSERT_FALSE(or_cond.match(3));
}

TEST(ConditionTest, OrConditionTestSame)
{
    OneCondition a;

    auto and_cond = a || a || OneCondition{};

    ASSERT_FALSE(and_cond.match(0));
    ASSERT_TRUE(and_cond.match(1));
    ASSERT_FALSE(and_cond.match(2));
    ASSERT_FALSE(and_cond.match(3));
}

TEST(ConditionTest, OrAndConditionTest)
{
    OneCondition a;

    auto or_cond = (a && TwoCondition{}) || TwoCondition{};

    ASSERT_FALSE(or_cond.match(0));
    ASSERT_FALSE(or_cond.match(1));
    ASSERT_TRUE(or_cond.match(2));
    ASSERT_FALSE(or_cond.match(3));
}