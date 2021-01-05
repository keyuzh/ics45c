#include <iostream>
#include <string>
#include "BaseClass.hpp"

BaseClass::BaseClass()
{
}


unsigned int BaseClass::getInt1() const
{
    std::cout << "getInt1 from BaseClass" << std::endl;
    return int1;
}
    
unsigned int BaseClass::getInt2() const
{
    std::cout << "virtual getInt2 from BaseClass" << std::endl;
    return int2;
}
