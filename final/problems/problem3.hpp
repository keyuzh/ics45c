#ifndef PROBLEM3_HPP
#define PROBLEM3_HPP

#include <functional>
#include <iostream>
#include <vector>



void applyAndPrintInReverse(
    std::ostream& out,
    const std::vector<int>& v,
    std::function<int(int)> f);



#endif

