// compute.cpp
// ICS45C Fall 2020 Project 1
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#include <cmath>
#include <string>
#include "compute.hpp"


// input num in degrees, change it to radian
void convertDegreeToRadian(double& num)
{
    num = num * M_PI / 180;
}


// helper function, converts all variables to radian
void convertAllToRadian(double& dlat, double& dlon, double& lat1, double& lon1, double& lat2, double& lon2)
{
    convertDegreeToRadian(dlat);
    convertDegreeToRadian(dlon);
    convertDegreeToRadian(lat1);
    convertDegreeToRadian(lon1);
    convertDegreeToRadian(lat2);
    convertDegreeToRadian(lon2);
}


// computes the difference in latitude and longitude
void computeDifference(double& dlat, double& dlon, double lat1, double lon1, double lat2, double lon2)
{
    dlat = std::fabs(lat1 - lat2);
    dlon = std::fabs(lon1 - lon2);
    // if dlon is greater than 180 degrees, then its closer the other way around
    if (dlon > 180)
    {
        dlon = 360 - dlon;
    }
}


// computes the distance between two points in miles,
// given the coordinates of two points
double computeDistance(double lat1, double lon1, double lat2, double lon2)
{
    double RADIUS_OF_EARTH = 3959.9;
    double dlat, dlon;

    computeDifference(dlat, dlon, lat1, lon1, lat2, lon2);
    convertAllToRadian(dlat, dlon, lat1, lon1, lat2, lon2);
    
    // implements the formula
    double a = std::pow(std::sin(dlat/2), 2) + std::cos(lat1) * std::cos(lat2) * std::pow(std::sin(dlon/2), 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    double d = RADIUS_OF_EARTH * c;

    return d;
}


// set either the closest or the farthest place to the new place
void setNewPlace(
    double& distance, double& latitude, double& longitude, std::string& location,
    double newDistance, double newLatitude, double newLongitude, std::string newLocation
    )
{
    distance = newDistance;
    latitude = newLatitude;
    longitude = newLongitude;
    location = newLocation;
}
