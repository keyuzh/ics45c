// cleanup.cpp
// ICS45C Fall 2020 Project 2
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#include "structs.hpp"

// delete all dynamically allocated variables
void cleanUp(Students*& students, Artifacts*& artifacts, const unsigned int numOfStudents)
{
    delete artifacts->pointsPossible;
    delete artifacts->weights;
    delete artifacts;
    for (unsigned int i = 0; i < numOfStudents; i++)
    {
        delete students[i].scores;
    }
    delete[] students;
}
