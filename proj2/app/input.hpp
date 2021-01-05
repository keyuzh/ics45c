// input.hpp
// ICS45C Fall 2020 Project 2
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#ifndef INPUT_HPP
#define INPUT_HPP

#include "structs.hpp"

// get a number from input
unsigned int getNumber();

// allocate and return a struct with artifact points
Artifacts* gradedArtifacts(const unsigned int num);

// fill a gradebook with all students' grades
void fillScores(Students*& gradebook, const unsigned int numOfArtifacts, const unsigned int numOfStudents);

// allocate and fill a gradebook with student info
Students* students(const unsigned int numOfStudents, const unsigned int numOfArtifacts);

#endif
