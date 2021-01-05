#ifndef PROBLEM6_HPP
#define PROBLEM6_HPP

#include <algorithm>

template <typename iterator1, typename iterator2, typename outputIterator, typename func>
void combine(
    iterator1 firstBegin, iterator1 firstEnd, 
    iterator2 secondBegin, iterator2 secondEnd, 
    outputIterator out, func f)
{
    auto i = firstBegin;
    auto j = secondBegin;
    while (i != firstEnd && j != secondEnd)
    {
        std::fill_n(out, 1, f(*i, *j));
        i++;
        j++;
        out++;
    }
}

#endif
