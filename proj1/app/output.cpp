// output.cpp
// ICS45C Fall 2020 Project 1
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#include <string>
#include <iostream>
#include "output.hpp"


void printSpace()
{
    std::cout << " ";
}


// print out the latitude or longitude in format '12.3456/N'
void printCoord(double coordinate, std::string coordType)
{
    std::cout << std::abs(coordinate) << "/";

    if (coordinate >= 0)  // N or E for positive value
    {
        if (coordType == "lat")
        {
            std::cout << "N";
        }
        else if (coordType == "lon")
        {
            std::cout << "E";
        }
    }
    else  // S or W for negative value
    {
        if (coordType == "lat")
        {
            std::cout << "S";
        }
        else if (coordType == "lon")
        {
            std::cout << "W";
        }
    }
}


// print out an entire line in the required format
void printLine(
    double latitude, double longitude, std::string location,
    bool includeDistance = false, double distance = 0
    )
{
    printCoord(latitude, "lat");    // latitude
    printSpace();
    printCoord(longitude, "lon");   // longitude
    printSpace();
    std::cout << "(" << location << ")";    // name of place in ()

    if (includeDistance == true)    // add the computed number of miles if needed
    {
        printSpace();
        std::cout << "(" << distance << " miles)";
    }
    std::cout << std::endl;  // final endlS
}


// output according to format
void finalPrintOut(
    std::string startLocation, double startLat, double startLon, 
    std::string closestLocation, double closestLat, double closestLon, double closestDist,
    std::string farthestLocation, double farthestLat, double farthestLon, double farthestDist   
)
{
    std::cout << "Start Location: ";    // first line
    printLine(startLat, startLon, startLocation);
    std::cout << "Closest Location: ";     // second line
    printLine(closestLat, closestLon, closestLocation, true, closestDist);
    std::cout << "Farthest Location: ";   // third line
    printLine(farthestLat, farthestLon, farthestLocation, true, farthestDist);
}
