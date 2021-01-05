#include <iostream>

int test2()
{
    return 2, 3;
}



double test1()
{
    return 1;
}



int main()
{
    int a, int b = test2();
    std::cout << a << b << std::endl;
    return 0;
}

