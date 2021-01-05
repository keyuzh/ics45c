// GroceryPurchase.cpp
//
// ICS 45C Fall 2020
// Exercise Set 4
//
// This is the implementation of the GroceryPurchase class.

#include "GroceryPurchase.hpp"


GroceryPurchase::GroceryPurchase(double taxRate)
    : taxRate{taxRate}, subtotal{0}, tax{0}
{
}


double GroceryPurchase::getTaxRate() const
{
    return taxRate;
}


unsigned int GroceryPurchase::getSubtotal() const
{
    return subtotal;
}


unsigned int GroceryPurchase::getTax() const
{
    return tax;
}


unsigned int GroceryPurchase::getTotal() const
{
    return getSubtotal() + getTax();
}


void GroceryPurchase::addItem(const GroceryItem& item)
{
    unsigned int itemCost = item.unitCount * item.unitPrice;
    subtotal += itemCost;

    if (item.isTaxable)
    {
        unsigned int itemTax = itemCost * taxRate;
        tax += itemTax;
    }
}


void GroceryPurchase::clear()
{
    subtotal = 0;
    tax = 0;
}

