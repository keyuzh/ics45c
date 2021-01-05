#include <iostream>
#include <string>

std::string generateSpace(int n)
{
    // Generate n spaces
    std::string result = "";
    for (int i = 0; i < n; i++)
    {
        result += " ";
    }
    return result;
}

std::string generateEndBlock()
{
    return "*";
}

std::string generateTopBlock(int n)
{
    // Generates the top block
    std::string result = "";

    for (int i = 0; i < n; i++)
    {
        result += "**";
    }

    result += generateEndBlock();   // add final "*"
    return result;
}

std::string generateMiddleBlock(int n)
{
    // Generates the middle block
    std::string result = "";

    for (int i = 0; i < n; i++)
    {
        result += "* ";
    }

    result += generateEndBlock();   // add final "*"
    return result;
}

std::string generateFinalLine(int n)
{
    return generateTopBlock(n);     // final line is the same as top line of same n
}

void generatePyramid(int n)
{
    for (int i = 1; i < (n+1); i++)
    {
        std::cout << generateSpace(n-i) << generateTopBlock(i) << std::endl;     // top line
        std::cout << generateSpace(n-i) << generateMiddleBlock(i) << std::endl;  // second line
    }

    std::cout << generateFinalLine(n) << std::endl;                              // final line
}

int main()
{
    int n; // input number n
    std::cin >> n;  // get input

    generatePyramid(n);
    
    for (int i = 0; i <= 10; i+=2)
    {
        std::cout << i << std::endl;
    }

    return 0;
}


