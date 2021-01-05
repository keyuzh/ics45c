// problem2.cpp
// ICS45C Fall 2020 Exercise Set 6
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#include "problem2.hpp"

std::map<std::string, unsigned int> countWordFrequencies(
    const std::vector<std::string>& words
    )
{
    std::map<std::string, unsigned int> m;

    for (const auto& w : words)
    {
        if (m.find(w) != m.end())  // see if the word is in map
        {
            m[w] = m[w] + 1;
        }
        else  // no match
        {
            m[w] = 1;
        }
    }
    return m;
}


std::string formatWordFrequencies(
    const std::map<std::string, unsigned int>& frequencies
    )
{
    // find longest word and digit in the map
    unsigned int maxWordLength = 0;
    unsigned int maxFrequencyDigit = 0;

    for (const auto& i: frequencies)
    {
        if (i.first.length() > maxWordLength)  // check word length
        {
            maxWordLength = i.first.length();
        }

        unsigned int len = std::to_string(i.second).length();  // check digit length
        if (len > maxFrequencyDigit)
        {
            maxFrequencyDigit = len;
        }
    }

    std::string result = "";

    for (const auto& i: frequencies)  // add each word into string
    {
        // add word
        result += i.first;

        // add spaces
        unsigned int numOfSpaceReqd = 2 +
            (maxWordLength - i.first.length()) +
            (maxFrequencyDigit - std::to_string(i.second).length());
        for (unsigned int i = 0; i < numOfSpaceReqd; i++)
        {
            result += " ";
        }

        // add digit and endl
        result += std::to_string(i.second);
        result += "\n";
    }
    return result;
}
