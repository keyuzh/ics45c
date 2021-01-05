// Widget.cpp
//
// ICS 45C Fall 2020
// Code Example
//
// Implementation of the Widget class

#include "Widget.hpp"
#include <iostream>


// Notice that we're defining what looks like a global variable here.
// However, it's actually not a global variable -- and, in fact, this is
// not even a declaration, since we've qualified its name with "Widget::"
// in front of it.  The compiler will only allow this if the Widget class
// has such a (static) member variable already declared (which it does).
//
// I've also initialized the widgetCount to 0.
unsigned int Widget::widgetCount = 0;


// The constructor, copy constructor, and destructor are not especially
// interesting here *except* in the way that they use the static member
// variable "widgetCount".  Notice that I've used the syntax
// "Widget::widgetCount".  As it turns out, it would be legal to just say
// "widgetCount" (since these are part of the Widget class already), but I
// think there's value in making the uses of widgetCount look like uses of
// a static member variable, so I've explicitly said "Widget::widgetCount".

Widget::Widget(int id)
    : id{id}
{
    Widget::widgetCount++;
}


Widget::Widget(const Widget& w)
    : id{w.id}
{
    Widget::widgetCount++;
}


Widget::~Widget()
{
    Widget::widgetCount--;
}


int Widget::getId() const
{
    std::cout << widgetCount << std::endl;
    return id;
}


// Notice that the definition of a static member function doesn't include the
// word "static" and that it otherwise looks just like a non-static member
// function.  The declaration of this member function (in the class declaration)
// establishes that it's static.

unsigned int Widget::getWidgetCount()
{
    // std::cout << id << std::endl;
    return widgetCount;
}

