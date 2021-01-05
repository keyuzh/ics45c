// age.cpp
//
// ICS 45C Fall 2020
// Code Example
//
// This file defines functions that provide age-related calculations.
//
// (More details about the mechanisms in use here are described in the
// file "input.cpp".)

#include "age.hpp"


// This is the declaration (and definition) of a global constant.  In
// general, we should avoid global variables -- for all of the reasons
// you've no doubt learned in other courses already -- but global constants
// are not particularly problematic, because their values don't change
// (so we aren't entrusting our entire program to know the rules that
// their values need to follow in order to be reasonable).
const int DAYS_PER_YEAR = 365;


int convertDaysToYears(int days)
{
    return days / DAYS_PER_YEAR;
}


int convertYearsToDays(int years)
{
    return years * DAYS_PER_YEAR;
}

