#ifndef PROBLEM2_HPP
#define PROBLEM2_HPP

#include <functional>
#include <fstream>
#include "FileException.hpp"
#include <iostream>



template <typename LineType>
class TextLineReader
{
public:
    using LineParser = std::function<LineType(const std::string&)>;

public:
    TextLineReader(const std::string& filePath, LineParser lineParser);
    ~TextLineReader();

    TextLineReader(const TextLineReader& other) = delete;
    TextLineReader& operator=(const TextLineReader& other) = delete;

    bool hasNextLine() const;
    LineType nextLine();

private:
    std::ifstream file;
    LineParser parser;
    bool parseFail;
    std::string nextText;
};


template <typename LineType>
TextLineReader<LineType>::TextLineReader(
    const std::string& filePath, LineParser lineParser
    )
    : file{filePath}, parser{lineParser}, parseFail{false}
{
    std::getline(file, nextText);
}


template <typename LineType>
TextLineReader<LineType>::~TextLineReader()
{
    file.close();
}


template <typename LineType>
bool TextLineReader<LineType>::hasNextLine() const
{
    return !(parseFail || file.eof());
}


template <typename LineType>
LineType TextLineReader<LineType>::nextLine()
{
    if (file.is_open() && hasNextLine())
    {
        std::string next;
        std::getline(file, next);
        LineType value;
        try
        {
            value = parser(nextText);
        }
        catch(...)
        {
            parseFail = true;
            throw;
        }
        nextText = next;
        return value;
    }
    throw FileException{"no next line"};
}


#endif

