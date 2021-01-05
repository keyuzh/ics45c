// main.cpp
//
// ICS 45C Fall 2020
// Code Example
//
// A little program that calls functions that we've declared and defined
// elsewhere.


// As a general rule, when we include header files from external libraries
// like the C++ Standard Library, we'll surround their names with angle-
// brackets; when we include our own header files, we'll surround their
// names with double-quotes.
#include <iostream>
#include <string>

// Meanwhile, this is how you include header files from your own project,
// by surrounding their names with double-quotes instead.
#include "age.hpp"
#include "input.hpp"


int main()
{
    std::cout << "Name: ";
    std::string name = readName();

    std::cout << "Age in Years: ";
    int ageInYears = readInt();

    int ageInDays = convertYearsToDays(ageInYears);

    std::cout << name << " is approximately " << ageInDays << " days old." << std::endl;

    return 0;
}

