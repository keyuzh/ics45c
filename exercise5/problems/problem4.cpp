// problem4.cpp
// ICS45C Fall 2020 Exercise Set 5
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#include "problem4.hpp"

// initializaiton
DynamicPair::DynamicPair(int initialInt, double initialDouble)
    : intValue{new int}, doubleValue{new double}
{
    changeInt(initialInt);
    changeDouble(initialDouble);
}

// destruction
DynamicPair::~DynamicPair()
{
    delete intValue;
    delete doubleValue;
}

// copy initialization
DynamicPair::DynamicPair(const DynamicPair& old)
    : intValue{new int}, doubleValue{new double}
{
    *intValue = old.getInt();
    *doubleValue = old.getDouble();
}

// copy assignment
DynamicPair& DynamicPair::operator=(const DynamicPair& right)
{
    if (this != &right)
    {
        int* newInt = new int;
        double* newDouble = new double;
        *newInt = right.getInt();
        *newDouble = right.getDouble();

        delete intValue;
        delete doubleValue;
        intValue = newInt;
        doubleValue = newDouble;
    }
    return *this;
}

// get int value
int DynamicPair::getInt() const
{
    return *intValue;
}

// get double value
double DynamicPair::getDouble() const
{
    return *doubleValue;
}

// change int value
void DynamicPair::changeInt(int newValue)
{
    if (newValue > 0)
    {
        newValue = 0;
    }

    *intValue = newValue;
}

// change double value
void DynamicPair::changeDouble(double newValue)
{
    if (newValue < 3)
    {
        newValue = 3;
    }

    *doubleValue = newValue;
}
