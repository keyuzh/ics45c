#include <gtest/gtest.h>
#include "GroceryItem.hpp"
#include "GroceryPurchase.hpp"


TEST(GroceryItemTests, itemDescriptionIsCorrent)
{
    GroceryItem item{"Apple", 12, 799, true};
    ASSERT_EQ("Apple", item.description);
}

TEST(GroceryItemTests, itemCountIsCorrent)
{
    GroceryItem item{"Apple", 12, 799, true};
    ASSERT_EQ(12, item.unitCount);
}

TEST(GroceryItemTests, itemPriceIsCorrent)
{
    GroceryItem item{"Apple", 12, 799, true};
    ASSERT_EQ(799, item.unitPrice);
}

TEST(GroceryItemTests, itemTaxable)
{
    GroceryItem item{"Apple", 12, 799, true};
    ASSERT_TRUE(item.isTaxable);
}

TEST(GroceryItemTests, itemNotTaxable)
{
    GroceryItem item{"Banana", 4, 3, false};
    ASSERT_FALSE(item.isTaxable);
}

TEST(GroceryPurchaseTests, defaultTaxRateIsZero)
{
    GroceryPurchase purchase{};
    ASSERT_EQ(0, purchase.getTaxRate());
}

TEST(GroceryPurchaseTests, taxRateIsCorrect)
{
    GroceryPurchase purchase{0.095};
    ASSERT_FLOAT_EQ(0.095, purchase.getTaxRate());
}

TEST(GroceryPurchaseTests, defaultSubtotalIsZero)
{
    GroceryPurchase purchase{};
    ASSERT_EQ(0, purchase.getSubtotal());
}

TEST(GroceryPurchaseTests, testSubTotalAfterAddingOneItem)
{
    GroceryPurchase purchase{};
    GroceryItem item{"Apple", 1, 799, true};
    purchase.addItem(item);
    ASSERT_EQ(799, purchase.getSubtotal());
}

TEST(GroceryPurchaseTests, testSubTotalAfterAddingOneItemOfMultipleQuantity)
{
    GroceryPurchase purchase{};
    GroceryItem item{"Banana", 7, 3, true};
    purchase.addItem(item);
    ASSERT_EQ(21, purchase.getSubtotal());
}

TEST(GroceryPurchaseTests, testSubTotalAfterAddingMultipleItems)
{
    GroceryPurchase purchase{};
    GroceryItem item{"Apple", 1, 799, true};
    GroceryItem item2{"Banana", 7, 3, true};
    purchase.addItem(item);
    purchase.addItem(item2);
    ASSERT_EQ(820, purchase.getSubtotal());
}

TEST(GroceryPurchaseTests, testTaxAmountIsCorrect)
{
    GroceryPurchase purchase{0.1};
    GroceryItem item{"Banana", 1, 20, true};
    purchase.addItem(item);
    ASSERT_EQ(2, purchase.getTax());
}

TEST(GroceryPurchaseTests, testTaxAmountIsCorrectMultipleItems)
{
    GroceryPurchase purchase{0.1};
    GroceryItem item{"Apple", 1, 500, true};
    GroceryItem item2{"Banana", 7, 300, true};
    purchase.addItem(item);
    purchase.addItem(item2);
    ASSERT_EQ(260, purchase.getTax());
}

TEST(GroceryPurchaseTests, testTaxAmountIsZeroForNonTaxable)
{
    GroceryPurchase purchase{0.1};
    GroceryItem item{"Banana", 1, 20, false};
    purchase.addItem(item);
    ASSERT_EQ(0, purchase.getTax());
}

TEST(GroceryPurchaseTests, testTaxAmountIsCorrectMultipleItemsMixedTaxable)
{
    GroceryPurchase purchase{0.1};
    GroceryItem item{"Apple", 1, 500, true};
    GroceryItem item2{"Banana", 7, 300, false};
    purchase.addItem(item);
    purchase.addItem(item2);
    ASSERT_EQ(50, purchase.getTax());
}

TEST(GroceryPurchaseTests, testGetTotalNoTax)
{
    GroceryPurchase purchase{};
    GroceryItem item{"Apple", 1, 799, true};
    purchase.addItem(item);
    ASSERT_EQ(799, purchase.getTotal());
}

TEST(GroceryPurchaseTests, testGetTotalWithTax)
{
    GroceryPurchase purchase{0.2};
    GroceryItem item{"Apple", 1, 800, true};
    purchase.addItem(item);
    ASSERT_EQ(960, purchase.getTotal());
}

TEST(GroceryPurchaseTests, testGetTotalWithNonTaxable)
{
    GroceryPurchase purchase{0.2};
    GroceryItem item{"Apple", 1, 800, false};
    purchase.addItem(item);
    ASSERT_EQ(800, purchase.getTotal());
}

TEST(GroceryPurchaseTests, testGetTotalMultipleItemsMixedTaxable)
{
    GroceryPurchase purchase{0.2};
    GroceryItem item{"Apple", 1, 500, true};
    GroceryItem item2{"Banana", 7, 300, false};
    purchase.addItem(item);
    purchase.addItem(item2);
    ASSERT_EQ(2700, purchase.getTotal());
}

TEST(GroceryPurchaseTests, testClearWithEmptyPurchase)
{
    GroceryPurchase purchase{0.2};
    purchase.clear();
    ASSERT_EQ(0, purchase.getSubtotal());
    ASSERT_EQ(0, purchase.getTax());
    ASSERT_EQ(0, purchase.getTotal());
}

TEST(GroceryPurchaseTests, testClearWithPurchase)
{
    GroceryPurchase purchase{0.2};
    GroceryItem item{"Apple", 1, 500, true};
    purchase.addItem(item);
    ASSERT_EQ(600, purchase.getTotal());  // confirm item added to total
    purchase.clear();  // everything should be zero now
    ASSERT_EQ(0, purchase.getSubtotal());
    ASSERT_EQ(0, purchase.getTax());
    ASSERT_EQ(0, purchase.getTotal());
}
