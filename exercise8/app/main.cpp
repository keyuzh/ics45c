#include <charconv>
#include <iostream>
#include <string>
#include "FileException.hpp"
#include "problem2.hpp"


int parseIntLine(const std::string& line)
{
    int value;

    const char* begin = line.data();
    const char* end = line.data() + line.size();

    auto result = std::from_chars(begin, end, value);

    if (result.ptr != end || result.ec != std::errc{})
    {
        throw FileException{"format error: every line must contain only an integer"};
    }

    return value;
}


int main()
{
    std::string filePath;
    std::getline(std::cin, filePath);
    TextLineReader<int> reader{filePath, parseIntLine};
    try
    {
        // TextLineReader<int> reader{filePath, parseIntLine};

        while (reader.hasNextLine())
        {
            int value = reader.nextLine();
            std::cout << (value * value) << std::endl;
        }
    }
    catch (FileException& e)
    {
        std::cout << "FileException: " << e.what() << std::endl;
    }

    // std::cout << reader.hasNextLine() << std::endl;
    // try
    // {
    //     reader.nextLine();
    // }
    // catch(const FileException& e)
    // {
    //     std::cout << "correct" << std::endl;
    // }
    

    return 0;
}

