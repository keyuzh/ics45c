// structs.hpp
// ICS45C Fall 2020 Project 2
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#ifndef STRUCTS_HPP
#define STRUCTS_HPP

#include <string>

struct Students
{
    double finalScore;
    unsigned int id;
    unsigned int* scores;
    std::string gradeOption;
    std::string name;
};

struct Cutpointset
{
    double a;
    double b;
    double c;
    double d;
};

struct Artifacts
{
    unsigned int* pointsPossible;
    unsigned int* weights;
};

#endif
