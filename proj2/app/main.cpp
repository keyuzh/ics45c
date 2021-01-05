// main.cpp
// ICS45C Fall 2020 Project 2
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#include "cleanup.hpp"
#include "finalgrade.hpp"
#include "input.hpp"
#include "scores.hpp"
#include "structs.hpp"


int main()
{
    // get number of artifacts and store in struct Artifacts
    unsigned int numOfArtifacts = getNumber();
    Artifacts* artifacts = gradedArtifacts(numOfArtifacts);

    // get numboer of students and put their info in struct Students
    unsigned int numOfStudents = getNumber();
    Students* studentGradeBook = students(numOfStudents, numOfArtifacts);
    // put their raw scores into the gradebook
    fillScores(studentGradeBook, numOfArtifacts, numOfStudents);

    // calculate total scores
    calculateAllScores(artifacts, studentGradeBook, numOfStudents, numOfArtifacts);
    // print out total scores
    printTotalScores(studentGradeBook, numOfStudents);

    // get input of cutpoints and print letter grade by cutpoints
    printByCutpoints(studentGradeBook, numOfStudents);

    // delete all dynamically allocated variables
    cleanUp(studentGradeBook, artifacts, numOfStudents);

    return 0;
}
