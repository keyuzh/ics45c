// finalgrade.hpp
// ICS45C Fall 2020 Project 2
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#ifndef FINALGRADE_HPP
#define FINALGRADE_HPP

#include <string>
#include "structs.hpp"

// print total numberic scores of all students
void printTotalScores(Students*& students, const unsigned int numOfStudents);

// get input of x setpoints and loop x times with scores calculated under that cutpoint 
void printByCutpoints(Students*& students, const unsigned int numOfStudents);

// returns the correct letter grade with selected grading option
// "G" == letter grade; "P" == pass/no pass
std::string calculateFinalGrade(
    Cutpointset& cutpoint, const double grade, std::string gradeOption
    );

#endif
