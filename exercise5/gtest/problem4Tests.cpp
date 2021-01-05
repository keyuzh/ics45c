#include <gtest/gtest.h>
#include "problem4.hpp"

TEST(DynamicPairTests, testClassCanStoreBoth)
{
    DynamicPair a(-123, 12.3456);
    ASSERT_FLOAT_EQ(12.3456, a.getDouble());
    ASSERT_EQ(-123, a.getInt());
}

TEST(DynamicPairTests, testIntNeverPositive)
{
    DynamicPair a(123, 12.3456);
    ASSERT_EQ(0, a.getInt());
}

TEST(DynamicPairTests, testDoubleNeverLessThanThree)
{
    DynamicPair a(-123, 1.234);
    ASSERT_FLOAT_EQ(3, a.getDouble());
}

TEST(DynamicPairTests, testIntCanChange)
{
    DynamicPair a(-3, 4.56);
    ASSERT_EQ(-3, a.getInt());
    a.changeInt(-123);
    ASSERT_EQ(-123, a.getInt());
    a.changeInt(-456);
    ASSERT_EQ(-456, a.getInt());
}

TEST(DynamicPairTests, testDoubleCanChange)
{
    DynamicPair a(-3, 3.45);
    ASSERT_FLOAT_EQ(3.45, a.getDouble());
    a.changeDouble(3.14);
    ASSERT_FLOAT_EQ(3.14, a.getDouble());
    a.changeDouble(6.28);
    ASSERT_FLOAT_EQ(6.28, a.getDouble());
}

TEST(DynamicPairTests, testCopyInitialization)
{
    DynamicPair a1(-123, 12.3456);
    ASSERT_FLOAT_EQ(12.3456, a1.getDouble());
    ASSERT_EQ(-123, a1.getInt());

    DynamicPair a2 = a1;
    ASSERT_FLOAT_EQ(12.3456, a2.getDouble());
    ASSERT_EQ(-123, a2.getInt());
}

TEST(DynamicPairTests, testCopyInitializationCanChangeValue)
{
    DynamicPair a1(-123, 12.3456);
    ASSERT_FLOAT_EQ(12.3456, a1.getDouble());
    ASSERT_EQ(-123, a1.getInt());

    DynamicPair a2 = a1;
    a2.changeDouble(123.456);
    a2.changeInt(-1234);
    ASSERT_FLOAT_EQ(123.456, a2.getDouble());
    ASSERT_EQ(-1234, a2.getInt());
    ASSERT_FLOAT_EQ(12.3456, a1.getDouble());
    ASSERT_EQ(-123, a1.getInt());
}

TEST(DynamicPairTests, testCopyInitializationCanChangeValue2)
{
    DynamicPair a1(-123, 12.3456);
    ASSERT_FLOAT_EQ(12.3456, a1.getDouble());
    ASSERT_EQ(-123, a1.getInt());

    DynamicPair a2 = a1;
    a2.changeDouble(123.456);
    a2.changeInt(-1234);

    ASSERT_FLOAT_EQ(12.3456, a1.getDouble());
    ASSERT_EQ(-123, a1.getInt());
    
    a1.changeDouble(23.4);
    a1.changeInt(-555);
    ASSERT_FLOAT_EQ(23.4, a1.getDouble());
    ASSERT_EQ(-555, a1.getInt());
    ASSERT_FLOAT_EQ(123.456, a2.getDouble());
    ASSERT_EQ(-1234, a2.getInt());
}

TEST(DynamicPairTests, testCopyAssignment)
{
    DynamicPair a1(-123, 12.3456);
    ASSERT_FLOAT_EQ(12.3456, a1.getDouble());
    ASSERT_EQ(-123, a1.getInt());

    DynamicPair a3(-1919, 114.514);
    ASSERT_FLOAT_EQ(114.514, a3.getDouble());
    ASSERT_EQ(-1919, a3.getInt());

    a1 = a3;

    ASSERT_FLOAT_EQ(114.514, a1.getDouble());
    ASSERT_EQ(-1919, a1.getInt());
}

TEST(DynamicPairTests, testCopyAssignmentCanChangeValue)
{
    DynamicPair a1(-123, 12.3456);
    ASSERT_FLOAT_EQ(12.3456, a1.getDouble());
    ASSERT_EQ(-123, a1.getInt());

    DynamicPair a3(-1919, 114.514);
    ASSERT_FLOAT_EQ(114.514, a3.getDouble());
    ASSERT_EQ(-1919, a3.getInt());

    a1 = a3;

    a3.changeDouble(114514.1919);
    a3.changeInt(-114514);

    ASSERT_FLOAT_EQ(114.514, a1.getDouble());
    ASSERT_EQ(-1919, a1.getInt());
    ASSERT_FLOAT_EQ(114514.1919, a3.getDouble());
    ASSERT_EQ(-114514, a3.getInt());
}

TEST(DynamicPairTests, testCopyAssignmentCanChangeValue2)
{
    DynamicPair a1(-123, 12.3456);
    ASSERT_FLOAT_EQ(12.3456, a1.getDouble());
    ASSERT_EQ(-123, a1.getInt());

    DynamicPair a3(-1919, 114.514);
    ASSERT_FLOAT_EQ(114.514, a3.getDouble());
    ASSERT_EQ(-1919, a3.getInt());

    a1 = a3;
    ASSERT_FLOAT_EQ(114.514, a1.getDouble());
    ASSERT_EQ(-1919, a1.getInt());

    a1.changeDouble(114514.1919);
    a1.changeInt(-114514);

    ASSERT_FLOAT_EQ(114.514, a3.getDouble());
    ASSERT_EQ(-1919, a3.getInt());
    ASSERT_FLOAT_EQ(114514.1919, a1.getDouble());
    ASSERT_EQ(-114514, a1.getInt());
}

// TEST(DynamicPariTests, testSelfAssignment)
// {
//     DynamicPair a3;
//     a3.changeDouble(114.514);
//     a3.changeInt(-1919);
//     ASSERT_FLOAT_EQ(114.514, a3.getDouble());
//     ASSERT_EQ(-1919, a3.getInt());

//     a3 = a3;
//     ASSERT_FLOAT_EQ(114.514, a3.getDouble());
//     ASSERT_EQ(-1919, a3.getInt());
// }