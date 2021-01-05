// inputoutput.cpp
// ICS45C Fall 2020 Project 3
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#include <iostream>
#include <string>
#include "inputoutput.hpp"


std::string readLine()
{
    // read a line of input
    std::string line;
    std::getline(std::cin, line);
    return line;
}


void printLine(const std::string& toPrint)
{
    // print a string on a line
    std::cout << toPrint << std::endl;
}


void printInt(const int& toPrint)
{
    // print a int on a line
    std::cout << toPrint << std::endl;
}


void printDouble(const double& toPrint)
{
    // print a double on a line
    std::cout << toPrint << std::endl;
}


void printInvalid()
{
    // print "INVALID\n"
    std::cout << "INVALID" << std::endl;
}
