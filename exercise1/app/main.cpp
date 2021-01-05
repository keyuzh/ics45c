#include <iostream>
#include <string>
#include <cmath>


void readAndConvert()
{
    int numOfTrades;
    std::string symbol;
    std::string description;
    
    // first line
    std::cin >> numOfTrades;
    // throw away newline char
    std::string temp;
    std::getline(std::cin, temp);

    // second line
    std::getline(std::cin, symbol);

    // third line
    std::getline(std::cin, description);

    // print out description
    std::cout << symbol << " (" << description << ")" << std::endl;

    // read trades
    for (int i = 0; i < numOfTrades; i++)
    {
        // read input of three piece
        std::string confirmationNumber;
        double price;
        unsigned int numOfShares;

        std::cin >> confirmationNumber >> price >> numOfShares;
        // throw away newline char
        std::string temp;
        std::getline(std::cin, temp);

        // compute total
        unsigned int total;
        total = std::floor(price * numOfShares);

        // print out total
        std::cout << "[" << confirmationNumber << "] " << total << std::endl;
    }
}

int main()
{

    readAndConvert();
    return 0;
}