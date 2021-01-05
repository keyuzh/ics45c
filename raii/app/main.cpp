// main.cpp
//
// ICS 45C Fall 2020
// Code Example
//
// Quick demonstration of our SmartIntPtr

#include <iostream>
#include "SmartIntPtr.hpp"


void f(SmartIntPtr& q)
{
    *q = 5;
}


void usingOne()
{
    SmartIntPtr p{new int{3}};
    f(p);

    std::cout << *p << std::endl;
    *p = 4;
    std::cout << *p << std::endl;
}


class MyKindOfException
{
};


// Even though this function throws an exception, p is still destroyed
// and its destructor is still called, which cleans up our dynamically-
// allocated integer automatically.
void automaticCleanup()
{
    SmartIntPtr p{new int{5}};
    throw MyKindOfException{};
}


int main()
{
    usingOne();

    try
    {
        automaticCleanup();
    }
    catch (MyKindOfException&)
    {
    }

    return 0;
}

