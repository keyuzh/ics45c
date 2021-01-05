#include "problem3.hpp"
#include <algorithm>

void applyAndPrintInReverse(
    std::ostream& out,
    const std::vector<int>& v,
    std::function<int(int)> f)
{
    std::for_each(v.rbegin(), v.rend(), [&](int n){out << f(n) << std::endl;});
}
