// inputoutput.hpp
// ICS45C Fall 2020 Project 3
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#ifndef INPUTOUTPUT_HPP
#define INPUTOUTPUT_HPP

#include <string>

// read a line of input
std::string readLine();

// print out things on a own line
void printLine(const std::string& toPrint);
void printInt(const int& toPrint);
void printDouble(const double& toPrint);

// print "INVALID\n"
void printInvalid();

#endif  // INPUTOUTPUT