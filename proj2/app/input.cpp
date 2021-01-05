// input.cpp
// ICS45C Fall 2020 Project 2
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#include <iostream>
#include "input.hpp"
#include "structs.hpp"


// get a number from input
unsigned int getNumber()
{
    unsigned int num;
    std::cin >> num;
    return num;
}


// allocate an array of 'size' from inputs
void allocateArray(unsigned int*& array, unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        unsigned int point;
        std::cin >> point;
        array[i] = point;
    }
}


// allocate and return a struct with artifact points
Artifacts* gradedArtifacts(const unsigned int num)
{
    // allocate two arrays in struct Artifact to store data
    Artifacts* artifacts = new Artifacts;
    artifacts->pointsPossible = new unsigned int[num];
    artifacts->weights = new unsigned int[num];

    allocateArray(artifacts->pointsPossible, num);
    allocateArray(artifacts->weights, num);

    return artifacts;
}


// fill gradebook with student info from input
void fillStudents(Students*& gradeBook, const unsigned int numOfStudents)
{
    for (unsigned i = 0; i < numOfStudents; i++)
    {
        unsigned int id;
        std::string gradeOption;
        std::string name;

        std::cin >> id >> gradeOption;
        std::cin.ignore(1);  // ignore 1 whitespace between grade option and name
        std::getline(std::cin, name);

        gradeBook[i].id = id;
        gradeBook[i].gradeOption = gradeOption;
        gradeBook[i].name = name;
    }
}


// allocate and fill array of scores with zero
void fillZeroScore(Students*& gradeBook, const unsigned int numOfStudents, const unsigned int numOfArtifacts)
{
    for (unsigned int i = 0; i < numOfStudents; i++)
    {
        // allocate
        gradeBook[i].scores = new unsigned int[numOfArtifacts];
        
        for (unsigned int j = 0; j < numOfArtifacts; j++)
        {
            gradeBook[i].scores[j] = 0;
        }
    }
}


// get number from input and set scores of a student
void setScores(unsigned int*& scores, const unsigned int numOfArtifacts)
{
    for (unsigned int i = 0; i < numOfArtifacts; i++)
    {
        unsigned int point;
        std::cin >> point;

        scores[i] = point;
    }
}


// fill a gradebook with all students' grades
void fillScores(Students*& gradebook, const unsigned int numOfArtifacts, const unsigned int numOfStudents)
{
    unsigned int numOfScores = getNumber();
    for (unsigned int i = 0; i < numOfScores; i++)
    {
        // input id number
        unsigned int id = getNumber();

        // find the id in gradeBook
        bool idFound = false;
        for (unsigned j = 0; j < numOfStudents; j++)
        {
            if (gradebook[j].id == id)  // found a matching id
            {
                setScores(gradebook[j].scores, numOfArtifacts);
                idFound = true;
                break;
            }
        }
        if (idFound == false)  // student not found in class
        {
            // throw away rest of line
            std::string temp;
            std::getline(std::cin, temp);
        }
    }
}


// allocate and fill a gradebook with student info
Students* students(const unsigned int numOfStudents, const unsigned int numOfArtifacts)
{
    Students* gradeBook = new Students[numOfStudents];

    fillStudents(gradeBook, numOfStudents);
    fillZeroScore(gradeBook, numOfStudents, numOfArtifacts);

    return gradeBook;
}
