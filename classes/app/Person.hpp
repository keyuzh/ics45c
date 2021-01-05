
#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include "Song.hpp"

class Person
{
private:
    std::string name;
    Song favoriteSong;

public:
    Person(std::string initialname, std::string initialartist, std::string initialtitle);
    void printPerson();

};



#endif