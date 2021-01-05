// DynamicTripleTests.cpp
//
// ICS 45C Fall 2020
// Code Example
//
// A handful of Google Test unit tests that demonstrate a few of the
// things that DynamicTriples do.

#include <stdexcept>
#include <string>
#include <gtest/gtest.h>
#include "DynamicTriple.hpp"


TEST(DynamicTripleTests, defaultConstructedTriplesHaveDefaultConstructedValues)
{
    DynamicTriple<std::string, std::string, std::string> t;

    EXPECT_EQ(std::string{""}, t.a());
    EXPECT_EQ(std::string{""}, t.b());
    EXPECT_EQ(std::string{""}, t.c());
}


TEST(DynamicTripleTests, triplesCanBeConstructedWithCopiesOfValues)
{
    DynamicTriple<int, double, unsigned int> t{3, -3.5, 40};

    EXPECT_EQ(3, t.a());
    EXPECT_EQ(-3.5, t.b());
    EXPECT_EQ(40, t.c());
}


TEST(DynamicTripleTests, triplesCanBeClearedBackToDefaultConstructedValues)
{
    DynamicTriple<std::string, std::string, std::string> t{"Boo", "is", "happy"};

    t.clear();

    EXPECT_EQ(std::string{""}, t.a());
    EXPECT_EQ(std::string{""}, t.b());
    EXPECT_EQ(std::string{""}, t.c());
}


namespace
{
    class ThrowingCopyConstructor
    {
    public:
        ThrowingCopyConstructor() { }

        ThrowingCopyConstructor(const ThrowingCopyConstructor& tcc)
        {
            throw std::runtime_error{"Doh"};
        }
    };
}


TEST(DynamicTripleTests, constructingTriplesFailsWhenCopyingParametersFails)
{
    try
    {
        DynamicTriple<ThrowingCopyConstructor, int, int> t{ThrowingCopyConstructor{}, 3, 3};
        FAIL() << "should have thrown std::runtime_error, but didn't";
    }
    catch (std::runtime_error&)
    {
    }

    // Note that this pattern is so common, there's a way to say it
    // more directly using Google Test using ASSERT_THROW.
    //
    // ASSERT_THROW(
    //     DynamicTriple<ThrowingCopyConstructor, int, int>{
    //         ThrowingCopyConstructor{}, 3, 3},
    //     std::runtime_error);
    //
    // The first argument can be any exception of statement, while
    // the second specifies the type of exception you expect will
    // be thrown.  The assert succeeds if the appropriate kind of
    // exception is thrown; it fails if not.
}

