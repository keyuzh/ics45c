// GroceryItem.hpp
//
// ICS 45C Fall 2020
// Exercise Set 4
//
// A GroceryItem represents one item that might be part of a grocery
// receipt.  It's made up of a few values:
//
// * A description, which is a string that describes what it is.
// * A unit count, which indicates how many of that item are being
//   purchased.
// * A unit price, in cents, which indicates how much each one
//   costs.
// * A bool value indicating whether sales tax is to be applied to
//   the item.
//
// So, for example, is someone was purchasing four gallons of milk
// for $3.25 each and milk was taxable, a GroceryItem struct
// representing that might be constructed this way:
//
//     GroceryItem item;
//     item.description = "Gallon of Milk";
//     item.unitCount = 4;
//     item.unitPrice = 325;
//     item.isTaxable = true;
//
// or, using the uniform initialization syntax, like this instead:
//
//     GroceryItem item{"Gallon of Milk", 4, 325, true};

#ifndef GROCERYITEM_HPP
#define GROCERYITEM_HPP

#include <string>



struct GroceryItem
{
    std::string description;
    unsigned int unitCount;
    unsigned int unitPrice;
    bool isTaxable;
};



#endif

