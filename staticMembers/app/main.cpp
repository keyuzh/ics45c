// main.cpp
//
// ICS 45C Fall 2020
// Code Example
//
// This is an example of creating, destroying, copying, and assigning Widget
// objects, printing the widget count at various points throughout the
// program.  Trace through this code by hand and see if you can determine
// what the output should be.  Then, run the program and see if you got
// what you expected; if you didn't, make sure you understand why.

#include <iostream>
#include "Widget.hpp"


void printWidgetCount(const std::string& location)
{
    std::cout << location << ": " << Widget::getWidgetCount() << std::endl;
}


void foo()
{
    printWidgetCount("foo1");
    Widget w1{5};
    printWidgetCount("foo2");
    Widget w2{7};
    printWidgetCount("foo3");
    w1 = w2;
    printWidgetCount("foo4");
}


void bar()
{
    printWidgetCount("bar1");
    Widget w3{10};
    printWidgetCount("bar2");
    w3.getId();
}


int main()
{
    printWidgetCount("main1");
    foo();
    printWidgetCount("main2");
    bar();
    printWidgetCount("main3");

    return 0;
}

