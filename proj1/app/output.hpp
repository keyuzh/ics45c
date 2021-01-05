// output.hpp
// ICS45C Fall 2020 Project 1
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <string>

// output according to format
void finalPrintOut(
    std::string startLocation, double startLat, double startLon, 
    std::string closestLocation, double closestLat, double closestLon, double closestDist,
    std::string farthestLocation, double farthestLat, double farthestLon, double farthestDist   
    );

#endif
