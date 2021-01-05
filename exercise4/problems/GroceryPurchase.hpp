// GroceryPurchase.hpp
//
// ICS 45C Fall 2020
// Exercise Set 4
//
// The job of a GroceryPurchase is to calculate the totals owed for a
// purchase of groceries made by a customer, given a sequence of
// GroceryItems.  It calculates three different values:
//
// * The subtotal, which is the total amount owed without including sales
//   tax.
// * The sales tax owed for any items that are taxable.
// * The overall total, which is the sum of the subtotal and the sales tax.
//
// All amounts are represented in cents.  Tax amounts are truncated to a
// number of cents on each item (e.g., if an item costs $1.99 without tax
// and the tax rate is 3.5%, the tax owed would be $0.06).

#ifndef GROCERYPURCHASE_HPP
#define GROCERYPURCHASE_HPP

#include "GroceryItem.hpp"



class GroceryPurchase
{
public:
    // Initializes a newly-created GroceryPurchase with the given
    // tax rate.  Note that the tax rate is a multiplier (i.e., the
    // amount by which you'd multiply an amount if you wanted to know
    // how much tax to charge), so you'd pass 0.025 if you wanted the
    // tax rate to be 2.5%.  The tax rate defaults to 0 if not
    // specified.
    GroceryPurchase(double taxRate = 0.0);

    // getTaxRate() returns the tax rate.
    double getTaxRate() const;

    // getSubtotal() returns the subtotal, in cents, of all of the
    // items already added.
    unsigned int getSubtotal() const;

    // getTax() returns the total sales tax, in cents, owed on all of
    // the items already added.
    unsigned int getTax() const;

    // getTotal() returns the total amount owed, in cents, on all of
    // the items already added.  The total is the subtotal plus the
    // sales tax.
    unsigned int getTotal() const;

    // addItem() adds an item to the various totals calculated for
    // this purchase.
    void addItem(const GroceryItem& item);

    // clear() clears all of the items from the purchase, with totals
    // reset to zero.
    void clear();

private:
    double taxRate;
    unsigned int subtotal;
    unsigned int tax;
};



#endif

