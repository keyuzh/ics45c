// finalgrade.cpp
// ICS45C Fall 2020 Project 2
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#include <iostream>
#include <string>
#include "finalgrade.hpp"
#include "input.hpp"
#include "structs.hpp"


// print total numberic scores of all students
void printTotalScores(Students*& students, const unsigned int numOfStudents)
{
    std::cout << "TOTAL SCORES" << std::endl;
    for (int i = 0; i < numOfStudents; i++)
    {
        std::cout << students[i].id << " ";
        std::cout << students[i].name << " ";
        std::cout << students[i].finalScore << std::endl;
    }
}


// print total letter grades of all students with a given cutpoint 
void printGrades(Students*& students, Cutpointset& cutpoints, const unsigned int numOfStudents)
{
    for (unsigned int i = 0; i < numOfStudents; i++)
    {
        std::cout << students[i].id << " ";
        std::cout << students[i].name << " ";
        std::cout << calculateFinalGrade(cutpoints, students[i].finalScore, students[i].gradeOption);
        std::cout << std::endl;
    }
}


// read cutpoints for letters and return a struct with all four points
Cutpointset cutPoint()
{
    double aCutPoint, bCutPoint, cCutPoint, dCutPoint;
    std::cin >> aCutPoint >> bCutPoint >> cCutPoint >> dCutPoint;

    Cutpointset cutPoints{aCutPoint, bCutPoint, cCutPoint, dCutPoint};
    return cutPoints;
}


// get input of x setpoints and loop x times with scores calculated under that cutpoint 
void printByCutpoints(Students*& students, const unsigned int numOfStudents)
{
    unsigned int numOfCutpoints = getNumber();
    for (size_t i = 1; i < numOfCutpoints+1; i++)
    {
        Cutpointset cutPoints = cutPoint();
        std::cout << "CUTPOINT SET " << i << std::endl;
        printGrades(students, cutPoints, numOfStudents);
    }
}


// returns the letter grade given cutpoints and number grade
std::string calculateLetterGrade(Cutpointset& cutpoint, const double grade)
{
    if (grade >= cutpoint.a)
    {
        return "A";
    }
    else if (grade >= cutpoint.b)
    {
        return "B";
    }
    else if (grade >= cutpoint.c)
    {
        return "C";
    }
    else if (grade >= cutpoint.d)
    {
        return "D";
    }
    else
    {
        return "F";
    }
}


// converts letter to pass/no pass grade
std::string letterToPassGrade(std::string letterGrade)
{
    if (letterGrade == "D" || letterGrade == "F")
    {
        return "NP";
    }
    else
    {
        return "P";
    }   
}


// returns the correct letter grade with selected grading option
// "G" == letter grade; "P" == pass/no pass
std::string calculateFinalGrade(Cutpointset& cutpoint, const double grade, std::string gradeOption)
{
    if (gradeOption == "G")
    {
        return calculateLetterGrade(cutpoint, grade);
    }
    else
    {
        return letterToPassGrade(calculateLetterGrade(cutpoint, grade));
    }
}
