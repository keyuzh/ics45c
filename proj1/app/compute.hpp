// compute.hpp
// ICS45C Fall 2020 Project 1
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#ifndef COMPUTE_HPP
#define COMPUTE_HPP

#include <string>

// computes the distance between two points in miles,
// given the coordinates of two points
double computeDistance(double lat1, double lon1, double lat2, double lon2);

// set either the closest or the farthest place to the new place
void setNewPlace(
    double& distance, double& latitude, double& longitude, std::string& location,
    double newDistance, double newLatitude, double newLongitude, std::string newLocation
);

#endif
