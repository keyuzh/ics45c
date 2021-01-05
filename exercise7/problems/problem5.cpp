// problem5.cpp
// ICS45C Fall 2020 Exercise Set 7
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#include "problem5.hpp"
#include <stdexcept>
#include <string>

namespace
{
    const unsigned int initialCapacity = 10;

    void arrayCopy(std::string* target, std::string* source, unsigned int size)
    {
        for (unsigned int i = 0; i < size; i++)
        {
            target[i] = source[i];
        }
    }
}


ArrayList::ArrayList()
    : items{new std::string[initialCapacity]}, sz{0}, cap{initialCapacity}
{
}


ArrayList::ArrayList(const ArrayList& a)
    : items{new std::string[a.cap]}, sz{a.sz}, cap{a.cap}
{
    arrayCopy(items, a.items, sz);
}


ArrayList::~ArrayList()
{
    delete[] items;
}

ArrayList& ArrayList::operator=(const ArrayList& a)
{
    if (this != &a)
    {
        std::string* newItems = new std::string[a.cap];
        arrayCopy(newItems, a.items, a.sz);

        sz = a.sz;
        cap = a.cap;

        delete[] items;
        items = newItems;
    }
    return *this;
}


std::string& ArrayList::at(unsigned int index)
{
    if (index >= sz)
    {
        std::string toThrow = "Invalid index: " + std::to_string(index) + 
            "; size of ArrayList is: " + std::to_string(sz);
        throw std::out_of_range(toThrow);
    }
    return items[index];
}


const std::string& ArrayList::at(unsigned int index) const
{
    if (index >= sz)
    {
        std::string toThrow = "Invalid index: " + std::to_string(index) + 
            "; size of ArrayList is: " + std::to_string(sz);
        throw std::out_of_range(toThrow);
    }
    return items[index];
}


void ArrayList::add(const std::string& s)
{
    if (sz == cap)
    {
        int newCap = cap * 2 + 1;

        std::string* newItems = new std::string[newCap];
        arrayCopy(newItems, items, sz);

        cap = newCap;

        delete[] items;
        items = newItems;
    }

    items[sz] = s;
    sz++;
}


unsigned int ArrayList::size() const
{
    return sz;
}


unsigned int ArrayList::capacity() const
{
    return cap;
}
