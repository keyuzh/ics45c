// expmain.cpp
//
// Do whatever you'd like here.  This is intended to allow you to experiment
// with the code in the "app" directory or with any additional libraries
// that are part of the project, outside of the context of the main
// application or Google Test.

#include <iostream>
#include "problem2.hpp"

int main()
{
    BaseClass base;
    unsigned int a = base.getInt1();
    std::cout << a << std::endl;

    unsigned int b = base.getInt2();
    std::cout << b << std::endl;

    InheritClass inherit;

    unsigned int c = inherit.getInt1();
    std::cout << c << std::endl;

    unsigned int d = inherit.getInt2();
    std::cout << d << std::endl;


    return 0;
}

