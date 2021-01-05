// scores.cpp
// ICS45C Fall 2020 Project 2
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#include "scores.hpp"
#include "structs.hpp"

// returns the final total score, given the weights and raw scores
double calculateTotalScore(
    Artifacts*& artifact, const unsigned int* rawScores, const unsigned int numOfArtifacts
    )
{
    double total = 0;
    for (unsigned int i = 0; i < numOfArtifacts; i++)
    {
        total += double(rawScores[i]) / double(artifact->pointsPossible[i]) * double(artifact->weights[i]);
    }
    return total;
}


// calculate the total score of all students
void calculateAllScores(
    Artifacts*& artifact, Students*& students,
    const unsigned int numOfStudents, const unsigned int numOfArtifacts
    )
{
    for (unsigned int i = 0; i < numOfStudents; i++)
    {
        students[i].finalScore = calculateTotalScore(artifact, students[i].scores, numOfArtifacts);
    }
}
