#include "problem2.hpp"
#include <vector>
#include <string>
#include <map>
#include <iostream>

int main()
{
    std::vector<std::string> v;

    for (int i = 0; i < 100; i++)
    {
        v.push_back("BOO");
    }
    
    for (int i = 0; i < 36; i++)
    {
        v.push_back("HELLO");
    }

    for (int i = 0; i < 20; i++)
    {
        v.push_back("QUICK");
    }

    for (int i = 0; i < 17; i++)
    {
        v.push_back("BOO");
    }

    for (int i = 0; i < 9; i++)
    {
        v.push_back("PERFECT");
    }

    for (int i = 0; i < 145; i++)
    {
        v.push_back("PERFECTLY");
    }

    auto m = countWordFrequencies(v);

    std::cout << formatWordFrequencies(m);

    return 0;
}

