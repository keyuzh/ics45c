#include "Person.hpp"
#include <iostream>
#include <string>

Person::Person(std::string initialname, std::string initialartist, std::string initialtitle)
      : name{initialname}, favoriteSong{initialartist, initialtitle}
{
    // name = initialname;
    // favoriteSong.setArtist(initialartist);
    // favoriteSong.setTitle(initialtitle);
}

void Person::printPerson()
{
    std::cout << name << favoriteSong.getArtist() << favoriteSong.getTitle() << std::endl;
}