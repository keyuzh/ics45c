// expmain.cpp
//
// Do whatever you'd like here.  This is intended to allow you to experiment
// with the code in the "app" directory or with any additional libraries
// that are part of the project, outside of the context of the main
// application or Google Test.

#include <string>
#include <iostream>
#include <list>
#include <algorithm>
#include <map>
#include <typeinfo>
#include <utility>
#include <numeric>
#include <vector>
// #include <ostream>
#include <functional>
#include <iterator>

#include "problem6.hpp"

// int square(int n)
// {
//     return n * n;
// }

// class Throwing
// {
// public:
//     Throwing()      { }
//     ~Throwing()     { throw std::runtime_error{"doh!"}; }
// };

int main()
{

    // std::string s = "perfect";
    // std::list<std::string> a1{"Boo", "is", s, "today"};
    // const std::list<std::string> a2{"Boo", "will", "always", "be", s};
    // std::map<int, double> m1{{3, 4.5}, {0, -7.25}, {1, 9.75}};


    // auto x  = std::accumulate(
    //     a1.begin(), a1.end(), std::string{}.size(),
    //     [](auto a, auto b) { return a + b.size(); });


    // unsigned long y = 17;
    // // std::string z = "hello";
    // // double w = 10.123;

    // std::cout << x << std::endl;

    // std::cout << typeid(x).name() << std::endl;
    // std::cout << typeid(y).name() << std::endl;

    // // std::cout << typeid(z).name() << std::endl;
    // // std::cout << typeid(w).name() << std::endl;
    // if (typeid(y) == typeid(x))
    // {
    //     std::cout << "x and y are the same type" << std::endl;
    // }
    
    // //std::cout << "x is int: " << 

    // std::vector<int> a = {};
    // for (int i = 0; i < 20; i++)
    // {
    //     a.push_back(i*2+1);
    // }
    
    // // std::ostream o{};


    // applyAndPrintInReverse(std::cout, a, square);

    std::vector<int> v1{1, 3, 5};
    // std::vector<int> v1{1, 3, 5, 7, 9};
    std::list<int> list1{2, 4, 6, 8, 10};
    // std::list<int> list1{2, 4, 6};
    std::vector<int> v2(5, 0);
    std::list<int> list2;

    combine(
        v1.begin(), v1.end(), list1.begin(), list1.end(), v2.begin(),
        [](int a, int b) { return a + b; });

    // At this point, v2 will contain five elements: 3, 7, 11, 15, 19

    for (auto i : v2)
    {
        std::cout << i << std::endl;
    }
    
    combine(
        list1.begin(), list1.end(), v1.begin(), v1.end(), std::back_inserter(list2),
        [](int a, int b) { return a * b; });

    // At this point, list2 will contain five elements: 2, 12, 30, 56, 90

    for (auto i : list2)
    {
        std::cout << i << std::endl;
    }

    return 0;
}

