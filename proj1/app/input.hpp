// input.hpp
// ICS45C Fall 2020 Project 1
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#ifndef INPUT_HPP
#define INPUT_HPP

#include <string>

// get the number of iterations
unsigned long getIterations();

// get a line in the format like:
// 33.9425/N 118.4081/W Los Angeles International Airport
// and store each variable into correct place
void getLocationLine(double& latitude, double& longitude, std::string& location);

#endif
