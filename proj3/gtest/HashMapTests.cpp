// HashMapTests.cpp
//
// ICS 45C Fall 2020
// Project #3: Maps and Legends
//
// Write unit tests for your HashMap class here.  I've provided a few tests
// already, though I've commented them out, because they won't compile and
// link until you've implemented some things.
//
// Of course, you'll want to write lots more of these tests yourself, because
// this is an inexpensive way to know whether things are working the way
// you expect -- including scenarios that you won't happen to hit in the
// course of testing your overall program.  (You might also want to be sure
// that your HashMap implementation is complete and correct before you try
// to write the rest of the program around it, anyway; there's a very
// substantial amount of partial credit available if all that works is
// HashMap.)

#include <gtest/gtest.h>
#include "HashMap.hpp"
#include <string>

namespace
{
    unsigned int ZeroHash(const std::string& s)
    {
        return 0;
    }

    unsigned int SpecialHash(const std::string& s)
    {
        // hash string by first letter
        return s[0];
    }
}

TEST(HashMapTests, sizeOfNewlyCreatedHashMapIsZero)
{
    HashMap empty;
    ASSERT_EQ(0, empty.size());
}

TEST(HashMapTests, emptyMapContainsNoKeys)
{
   HashMap empty;
   ASSERT_FALSE(empty.contains("first"));
   ASSERT_FALSE(empty.contains("second"));
}

TEST(HashMapTests, containKeyAfterAddingIt)
{
   HashMap hm;
   hm.add("Boo", "perfect");
   ASSERT_TRUE(hm.contains("Boo"));
}

TEST(HashMapTests, initialBucketCountIsCorret)
{
    HashMap hm;
    ASSERT_EQ(HashMap::INITIAL_BUCKET_COUNT, hm.bucketCount());
}

TEST(HashMapTests, initialLoadFactorIsZero)
{
    HashMap hm;
    ASSERT_FLOAT_EQ(0, hm.loadFactor());
}

TEST(HashMapTests, initialMaxBucketSizeIsZero)
{
    HashMap hm;
    ASSERT_EQ(0, hm.maxBucketSize());
}

TEST(HashMapTests, canAddKeyValuePair)
{
   HashMap hm;
   hm.add("Boo", "perfect");
}

TEST(HashMapTests, canAddMultipleKeyValuePair)
{
   HashMap hm;
   hm.add("Boo", "perfect");
   hm.add("Hello", "ICS45C");
}

TEST(HashMapTests, sizeChangeAfteAdding)
{
   HashMap hm;
   ASSERT_EQ(0, hm.size());
   hm.add("Boo", "perfect");
   ASSERT_EQ(1, hm.size());
}

TEST(HashMapTests, canCreateHashMapWithHashFunction)
{
    HashMap empty(ZeroHash);
    ASSERT_EQ(0, empty.size());
}

TEST(HashMapTests, canAddMultipleKeyValuePairWithHashFunction)
{
    HashMap hm(ZeroHash);
    ASSERT_EQ(0, hm.size());
    hm.add("Boo", "perfect");
    hm.add("Hello", "ICS45C");
    ASSERT_EQ(2, hm.size());
}

TEST(HashMapTests, canAddMultipleKeyValuePairWithHashFunction2)
{
    HashMap hm(ZeroHash);
    ASSERT_EQ(0, hm.size());
    hm.add("Boo", "perfect");
    hm.add("Hello", "ICS45C");
    ASSERT_EQ(2, hm.size());
    hm.add("arandomstring", "abcdefghijklmn");
    ASSERT_EQ(3, hm.size());
    hm.add("arandomstring2", "abcdefghijklmn");
}

TEST(HashMapTests, canContainMultipleItemsInSameBucket)
{
    HashMap hm(ZeroHash);
    ASSERT_EQ(0, hm.size());
    hm.add("Boo", "perfect");
    hm.add("Hello", "ICS45C");
    ASSERT_EQ(2, hm.size());
    ASSERT_TRUE(hm.contains("Boo"));
    ASSERT_TRUE(hm.contains("Hello"));
}

TEST(HashMapTests, canContainMultipleItemsInSameBucket2)
{
    HashMap hm(ZeroHash);
    ASSERT_EQ(0, hm.size());
    hm.add("Boo", "perfect");
    hm.add("Hello", "ICS45C");
    hm.add("arandomstring", "abcdefghijklmn");
    hm.add("arandomstring2", "abcdefghijklmn");
    hm.add("arandomstring3", "abcdefghijklmn");
    hm.add("arandomstring4", "abcdefghijklmn");
    hm.add("arandomstring5", "abcdefghijklmn");
    ASSERT_EQ(7, hm.size());
    ASSERT_TRUE(hm.contains("Boo"));
    ASSERT_TRUE(hm.contains("Hello"));
    ASSERT_TRUE(hm.contains("arandomstring"));
    ASSERT_TRUE(hm.contains("arandomstring2"));
    ASSERT_TRUE(hm.contains("arandomstring3"));
    ASSERT_TRUE(hm.contains("arandomstring4"));
    ASSERT_TRUE(hm.contains("arandomstring5"));
}

TEST(HashMapTests, testMaxBucketSize)
{
    HashMap hm(ZeroHash);
    hm.add("Boo", "perfect");
    hm.add("Hello", "ICS45C");
    ASSERT_EQ(2, hm.maxBucketSize());
}

TEST(HashMapTests, testMaxBucketSize2)
{
    HashMap hm(ZeroHash);
    hm.add("Boo", "perfect");
    hm.add("Hello", "ICS45C");
    hm.add("arandomstring", "abcdefghijklmn");
    hm.add("arandomstring2", "abcdefghijklmn");
    hm.add("arandomstring3", "abcdefghijklmn");
    hm.add("arandomstring4", "abcdefghijklmn");
    hm.add("arandomstring5", "abcdefghijklmn");
    ASSERT_EQ(7, hm.maxBucketSize());
}

TEST(HashMapTests, testMaxBucketSizeWithMultipleLinkedLists)
{
    HashMap hm(SpecialHash);
    hm.add("Boo", "perfect");
    hm.add("Hello1", "ICS45C");
    hm.add("Hello2", "ICS45C");
    hm.add("Hello3", "ICS45C");
    hm.add("arandomstring", "abcdefghijklmn");
    hm.add("arandomstring2", "abcdefghijklmn");
    hm.add("arandomstring3", "abcdefghijklmn");
    hm.add("arandomstring4", "abcdefghijklmn");
    hm.add("arandomstring5", "abcdefghijklmn");
    ASSERT_EQ(5, hm.maxBucketSize());
}

TEST(HashMapTests, returnCorrectValue)
{
   HashMap hm;
   hm.add("Boo", "perfect");
   ASSERT_EQ("perfect", hm.value("Boo"));
}

TEST(HashMapTests, returnCorrectValueMultiple)
{
   HashMap hm;
   hm.add("Boo", "perfect");
   hm.add("Hello", "ICS45C");
   ASSERT_EQ("perfect", hm.value("Boo"));
   ASSERT_EQ("ICS45C", hm.value("Hello"));
}

TEST(HashMapTests, returnEmptyStringIfKeyNotPresent)
{
   HashMap hm;
   hm.add("Boo", "perfect");
   ASSERT_EQ("", hm.value("Hello"));
   ASSERT_NE("ICS45C", hm.value("Hello"));
}

TEST(HashMapTests, canRemovePairFromBucket)
{
    HashMap hm;
    hm.add("Boo", "perfect");
    ASSERT_EQ(1, hm.size());
    ASSERT_TRUE(hm.contains("Boo"));
    ASSERT_EQ(1, hm.maxBucketSize());
    ASSERT_TRUE(hm.remove("Boo"));
    ASSERT_EQ(0, hm.size());
    ASSERT_FALSE(hm.contains("Boo"));
    ASSERT_EQ(0, hm.maxBucketSize());
}

TEST(HashMapTests, canRemovePairFromBucketMultiple)
{
    HashMap hm;
    hm.add("Boo", "perfect");
    hm.add("Hello", "ICS45C");
    ASSERT_EQ(2, hm.size());
    ASSERT_TRUE(hm.contains("Boo"));
    ASSERT_TRUE(hm.contains("Hello"));
    ASSERT_TRUE(hm.remove("Boo"));
    ASSERT_EQ(1, hm.size());
    ASSERT_FALSE(hm.contains("Boo"));
    ASSERT_TRUE(hm.contains("Hello"));
    ASSERT_TRUE(hm.remove("Hello"));
    ASSERT_EQ(0, hm.size());
    ASSERT_FALSE(hm.contains("Hello"));
    ASSERT_EQ(0, hm.maxBucketSize());
}

TEST(HashMapTests, canRemovePairFromBucketWithSpecialHashFunction)
{
    HashMap hm(ZeroHash);
    hm.add("Boo", "perfect");
    hm.add("Hello", "ICS45C");
    ASSERT_EQ(2, hm.size());
    ASSERT_TRUE(hm.contains("Boo"));
    ASSERT_TRUE(hm.contains("Hello"));
    ASSERT_EQ(2, hm.maxBucketSize());
    ASSERT_TRUE(hm.remove("Boo"));
    ASSERT_EQ(1, hm.size());
    ASSERT_FALSE(hm.contains("Boo"));
    ASSERT_TRUE(hm.contains("Hello"));
    ASSERT_TRUE(hm.remove("Hello"));
    ASSERT_EQ(0, hm.size());
    ASSERT_FALSE(hm.contains("Hello"));
    ASSERT_EQ(0, hm.maxBucketSize());
}

TEST(HashMapTests, canRemovePairFromBucketWithSpecialHashFunction2)
{
    HashMap hm(ZeroHash);
    hm.add("Boo", "perfect");
    hm.add("Hello", "ICS45C");
    ASSERT_EQ(2, hm.size());
    ASSERT_TRUE(hm.contains("Boo"));
    ASSERT_TRUE(hm.contains("Hello"));
    ASSERT_EQ(2, hm.maxBucketSize());
    ASSERT_TRUE(hm.remove("Hello"));
    ASSERT_EQ(1, hm.size());
    ASSERT_TRUE(hm.contains("Boo"));
    ASSERT_FALSE(hm.contains("Hello"));
    ASSERT_TRUE(hm.remove("Boo"));
    ASSERT_EQ(0, hm.size());
    ASSERT_FALSE(hm.contains("Boo"));
    ASSERT_EQ(0, hm.maxBucketSize());
}

TEST(HashMapTests, canClearTable)
{
    HashMap hm;
    hm.add("Boo", "perfect");
    hm.add("Hello", "ICS45C");
    ASSERT_EQ(2, hm.size());
    ASSERT_TRUE(hm.contains("Boo"));
    ASSERT_TRUE(hm.contains("Hello"));
    hm.clear();
    ASSERT_FALSE(hm.contains("Boo"));
    ASSERT_FALSE(hm.contains("Hello"));
    ASSERT_EQ(0, hm.size());
    ASSERT_EQ(0, hm.maxBucketSize());
}

TEST(HashMapTests, canClearTableZeroHash)
{
    HashMap hm(ZeroHash);
    hm.add("Boo", "perfect");
    hm.add("Hello1", "ICS45C");
    hm.add("Hello2", "ICS45C");
    hm.add("Hello3", "ICS45C");
    hm.add("arandomstring", "abcdefghijklmn");
    ASSERT_EQ(5, hm.size());
    ASSERT_TRUE(hm.contains("Boo"));
    ASSERT_TRUE(hm.contains("Hello1"));
    ASSERT_TRUE(hm.contains("Hello2"));
    ASSERT_TRUE(hm.contains("Hello3"));
    ASSERT_TRUE(hm.contains("arandomstring"));
    hm.clear();
    ASSERT_FALSE(hm.contains("Boo"));
    ASSERT_FALSE(hm.contains("Hello1"));
    ASSERT_FALSE(hm.contains("Hello2"));
    ASSERT_FALSE(hm.contains("Hello3"));
    ASSERT_FALSE(hm.contains("arandomstring"));
    ASSERT_EQ(0, hm.size());
    ASSERT_EQ(0, hm.maxBucketSize());
}

TEST(HashMapTests, canClearTableSpecialHash)
{
    HashMap hm(SpecialHash);
    hm.add("Boo", "perfect");
    hm.add("Hello1", "ICS45C");
    hm.add("Hello2", "ICS45C");
    hm.add("Hello3", "ICS45C");
    hm.add("arandomstring", "abcdefghijklmn");
    ASSERT_EQ(5, hm.size());
    ASSERT_EQ(3, hm.maxBucketSize());
    ASSERT_TRUE(hm.contains("Boo"));
    ASSERT_TRUE(hm.contains("Hello1"));
    ASSERT_TRUE(hm.contains("Hello2"));
    ASSERT_TRUE(hm.contains("Hello3"));
    ASSERT_TRUE(hm.contains("arandomstring"));
    hm.clear();
    ASSERT_FALSE(hm.contains("Boo"));
    ASSERT_FALSE(hm.contains("Hello1"));
    ASSERT_FALSE(hm.contains("Hello2"));
    ASSERT_FALSE(hm.contains("Hello3"));
    ASSERT_FALSE(hm.contains("arandomstring"));
    ASSERT_EQ(0, hm.size());
    ASSERT_EQ(0, hm.maxBucketSize());
}

TEST(HashMapTests, canRehash)
{
    HashMap hm;
    for (int i = 0; i < 8; i++)
    {
        char a = 'a' + i;
        std::string str = "Hello";
        hm.add(str+a, "someValue");
    }
    ASSERT_EQ(8, hm.size());
    double factor = double(8) / double(hm.INITIAL_BUCKET_COUNT);
    ASSERT_FLOAT_EQ(factor, hm.loadFactor());
    ASSERT_EQ(hm.INITIAL_BUCKET_COUNT, hm.bucketCount());

    // adding this pair should cause hashmap to rehash
    hm.add("valueThatCauseRehash", "someValue");

    factor = double(9) / double(hm.INITIAL_BUCKET_COUNT*2+1);
    ASSERT_EQ(9, hm.size());
    ASSERT_FLOAT_EQ(factor, hm.loadFactor());
    ASSERT_EQ(hm.INITIAL_BUCKET_COUNT*2+1, hm.bucketCount());
}

TEST(HashMapTests, notAddIfKeyAlreadyExist)
{
    HashMap hm;
    hm.add("Boo", "perfect");
    ASSERT_EQ(1, hm.size());
    hm.add("Boo", "alsoperfect");
    ASSERT_EQ(1, hm.size());
    ASSERT_EQ("perfect", hm.value("Boo"));
}

TEST(HashMapTests, copyConstructCanCopyCorrectValue)
{
    HashMap hm1;
    hm1.add("Boo", "perfect");
    hm1.add("Hello", "ICS45C");
    ASSERT_EQ(2, hm1.size());
    ASSERT_TRUE(hm1.contains("Boo"));
    ASSERT_TRUE(hm1.contains("Hello"));
    ASSERT_EQ("perfect", hm1.value("Boo"));
    ASSERT_EQ("ICS45C", hm1.value("Hello"));

    HashMap hm2 = hm1;
    ASSERT_TRUE(hm2.contains("Boo"));
    ASSERT_TRUE(hm2.contains("Hello"));
    ASSERT_EQ("perfect", hm2.value("Boo"));
    ASSERT_EQ("ICS45C", hm2.value("Hello"));

    ASSERT_EQ(hm1.size(), hm2.size());
    ASSERT_EQ(hm1.bucketCount(), hm2.bucketCount());
    ASSERT_FLOAT_EQ(hm1.loadFactor(), hm2.loadFactor());
    ASSERT_EQ(hm1.maxBucketSize(), hm2.maxBucketSize());
}

TEST(HashMapTests, copyConstructDoNotChangeOrigialValue)
{
    HashMap hm1;
    hm1.add("Boo", "perfect");
    hm1.add("Hello", "ICS45C");

    HashMap hm2 = hm1;

    hm2.add("this", "should not be in hm1");
    ASSERT_EQ(3, hm2.size());
    ASSERT_EQ(2, hm1.size());
    ASSERT_TRUE(hm2.contains("this"));
    ASSERT_FALSE(hm1.contains("this"));
}

TEST(HashMapTests, assignmentOperator)
{
    HashMap hm1;
    hm1.add("Boo", "perfect");
    hm1.add("Hello", "ICS45C");
    ASSERT_EQ(2, hm1.size());
    ASSERT_TRUE(hm1.contains("Boo"));
    ASSERT_TRUE(hm1.contains("Hello"));
    ASSERT_EQ("perfect", hm1.value("Boo"));
    ASSERT_EQ("ICS45C", hm1.value("Hello"));

    HashMap hm2;
    hm2.add("added", "to hm2 first");
    ASSERT_EQ(1, hm2.size());
    
    hm1 = hm2;

    ASSERT_EQ(1, hm1.size());
    ASSERT_FALSE(hm1.contains("Boo"));
    ASSERT_FALSE(hm1.contains("Hello"));
    ASSERT_TRUE(hm1.contains("added"));
    ASSERT_EQ("to hm2 first", hm1.value("added"));
}

TEST(HashMapTests, assignmentOperatorDoNotChangeOriginal)
{
    HashMap hm1;
    hm1.add("Boo", "perfect");
    hm1.add("Hello", "ICS45C");

    HashMap hm2;
    hm2.add("added", "to hm2 first");
    
    hm1 = hm2;
    hm2.add("this", "should not be in hm1");

    ASSERT_EQ(1, hm1.size());
    ASSERT_EQ(2, hm2.size());

    ASSERT_FALSE(hm1.contains("this"));
    ASSERT_TRUE(hm2.contains("this"));

    hm1.add("one more", "not in hm2");
    ASSERT_TRUE(hm1.contains("one more"));
    ASSERT_FALSE(hm2.contains("one more"));
}
