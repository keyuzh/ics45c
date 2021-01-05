// main.cpp
// ICS45C Fall 2020 Project 1
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

// #include <iomanip>
// #include <iostream>
#include <string>
#include "compute.hpp"
#include "input.hpp"
#include "output.hpp"

int main()
{
    double startLatitude, startLongitude;
    double closestDistance, closestLatitude, closestLongitude;
    double farthestDistance, farthestLatitude, farthestLongitude;
    std::string startLocation, closestLocation, farthestLocation;

    // get first line of input
    getLocationLine(startLatitude, startLongitude, startLocation);

    // second line, num of iterations
    unsigned long iterations = getIterations();
    for (unsigned long i = 0; i < iterations; ++i)
    {
        double newLatitude, newLongitude;
        std::string newLocation;
        getLocationLine(newLatitude, newLongitude, newLocation);
        // compute
        double newDistance = computeDistance(startLatitude, startLongitude, newLatitude, newLongitude);

        if (i == 0 || newDistance < closestDistance)  // new closest distance or first iteration
        {
            setNewPlace(
                closestDistance, closestLatitude, closestLongitude, closestLocation, 
                newDistance, newLatitude, newLongitude, newLocation
                );
        }
        if (i == 0 || newDistance > farthestDistance)  // new farthest distance or first iteration
        {
            setNewPlace(
                farthestDistance, farthestLatitude, farthestLongitude, farthestLocation, 
                newDistance, newLatitude, newLongitude, newLocation
                );
        }
    }

    // print out
    finalPrintOut(
        startLocation, startLatitude, startLongitude,
        closestLocation, closestLatitude, closestLongitude, closestDistance,
        farthestLocation, farthestLatitude, farthestLongitude, farthestDistance
    );

    return 0;
}

