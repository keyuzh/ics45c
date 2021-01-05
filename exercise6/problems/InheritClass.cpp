#include <iostream>
#include <string>
#include "InheritClass.hpp"

InheritClass::InheritClass()
{
}

// Q1-3
unsigned int InheritClass::getInt2() const
{
    std::cout << "getInt2 from InheritClass" << std::endl;
    return int4;
}

// Q4-5
// unsigned int InheritClass::getInt2Misspelled() const
// {
//     std::cout << "getInt2 from InheritClass" << std::endl;
//     return int4;
// }

// Q6-8
unsigned int InheritClass::getInt1() const
{
    std::cout << "getInt1 from InheritClass" << std::endl;
    return int3;
}

// Q9-10
// unsigned int InheritClass::getInt1Misspelled() const
// {
//     std::cout << "getInt1 from InheritClass" << std::endl;
//     return int3;
// }
