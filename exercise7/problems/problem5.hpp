// problem5.hpp
// ICS45C Fall 2020 Exercise Set 7
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#ifndef PROBLEM5_HPP
#define PROBLEM5_HPP

#include <string>

class ArrayList
{
public:
    ArrayList();
    ArrayList(const ArrayList& a);
    ~ArrayList();
    ArrayList& operator=(const ArrayList& a);

    std::string& at(unsigned int index);
    const std::string& at(unsigned int index) const;

    void add(const std::string& s);

    unsigned int size() const;

    unsigned int capacity() const;

private:
    std::string* items;
    unsigned int sz;
    unsigned int cap;
};

#endif  // PROBLEM5_HPP