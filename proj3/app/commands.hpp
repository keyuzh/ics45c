// commands.hpp
// ICS45C Fall 2020 Project 3
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <sstream>
#include <string>
#include "HashMap.hpp"

class Commands
{
public:
    // only constructor needed because hashmap is already well-behaved,
    // and there's no dynamic allocated variables in this class
    Commands();

    // gets command from input and execute them
    void mainLoop();


private:  // variables
    // hashmap class
    HashMap hashmap;

    // used to store the 3 words of command
    std::string parameter1;
    std::string parameter2;
    std::string parameter3;
    // whole line of command as string
    std::string commandString;
    // input as a stream
    std::stringstream commandStream;

    // number of words in the command, used to check format
    unsigned int wordCount;
    // flag to quit program
    bool quit;
    // flag for whether debug mode is on
    bool debug;


private:  // member functions
    // clears commandStream
    void clearStream();

    // get a line of command from input and store as string first
    void getCommand();

    // print "INVALID\n"
    void invalidInput();

    // check the length and first parameter from command
    void checkAndExecute();

    // checks word count of input is between acceptable range (1-3)
    bool checkWordCount();

    // At least one word inputed, we can use the first word to determine which
    // command to execute
    void setFirstParameter();

    // execute correct command base on the first parameter
    void executeCommand();

    // member functions to execute each command
    void executeQuit();
    void executeClear();
    void executeCreate();
    void executeLogin(bool parameterParsed=false);
    void executeRemove();
    // commands in debug mode
    void executeDebug();
    void executeDebugLoginCount();
    void executeBucketCount();
    void executeLoadFactor();
    void executeMaxBucketSize();
};

#endif // COMMANDS_HPP
