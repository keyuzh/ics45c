#include <string>
#include <iostream>


int main()
{
    int i = 3;
    double d = 3.5;
    std::string s = "Boo is perfect";
    int& j = i;
    int* k = new int{5};

    std::cout << i + 2 << std::endl;

    std::cout << i + j << std::endl;


    std::cout << i * d << std::endl;
    std::cout << typeid(i * d).name() << std::endl;

    char a = 2;
    std::cout << typeid(a).name() << std::endl;

    std::cout << s[*k] << std::endl;




    return 0;
}

