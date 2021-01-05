// problem4.hpp
// ICS45C Fall 2020 Exercise Set 5
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#ifndef PROBLEM4_HPP
#define PROBLEM4_HPP

class DynamicPair
{
private:
    // storing two pointers to two values
    int* intValue;
    double* doubleValue;
public:
    // initializaiton
    DynamicPair(int initialInt, double initialDouble);
    // destruction
    ~DynamicPair();
    // copy
    DynamicPair(const DynamicPair& old);
    DynamicPair& operator=(const DynamicPair& right);

    // get value
    int getInt() const;
    double getDouble() const;

    // change value
    void changeInt(int newValue);
    void changeDouble(double newValue);
};

#endif
