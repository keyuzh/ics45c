#ifndef PROBLEM2_HPP
#define PROBLEM2_HPP

#include <map>
#include <string>
#include <vector>


std::map<std::string, unsigned int> countWordFrequencies(
    const std::vector<std::string>& words);


std::string formatWordFrequencies(
    const std::map<std::string, unsigned int>& frequencies);


#endif

