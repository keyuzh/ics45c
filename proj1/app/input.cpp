// input.cpp
// ICS45C Fall 2020 Project 1
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#include <iostream>
#include <string>
#include "input.hpp"


// gets the name of location
std::string getLocationName()
{
    std::string result;
    std::getline(std::cin, result);
    return result.substr(1);  // get rid of a space in front
}


// get the number of iterations
unsigned long getIterations()
{
    unsigned long iterations;
    std::cin >> iterations;

    // throw away newline char
    std::string temp;
    std::getline(std::cin, temp);

    return iterations;
}


// get input in the format of 12.3456/N and return latitude or longitude in double,
// N and E are expressed in positive value while S and W are negative value
double getNumber()
{
    std::string location;
    std::cin >> location;

    // slice the string to get only the wanted part
    double result = std::stod(location.substr(0, location.size()-2));
    
    // if in S or W make it negative
    std::string lastchar = location.substr(location.size()-1);  // gets the last piece of string
    if (lastchar == "S" || lastchar == "W")
    {
        result = result * -1;
    }

    return result;
}


// get a line in the format like:
// 33.9425/N 118.4081/W Los Angeles International Airport
// and store each variable into correct place
void getLocationLine(double& latitude, double& longitude, std::string& location)
{
    latitude = getNumber();
    longitude = getNumber();
    location = getLocationName();
}
