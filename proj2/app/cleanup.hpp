// cleanup.hpp
// ICS45C Fall 2020 Project 2
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#ifndef CLEANUP_HPP
#define CLEANUP_HPP

#include "structs.hpp"

// delete all dynamically allocated variables
void cleanUp(Students*& students, Artifacts*& artifacts, const unsigned int numOfStudents);

#endif
