// commands.cpp
// ICS45C Fall 2020 Project 3
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#include <sstream>
#include <string>
#include "commands.hpp"
#include "inputoutput.hpp"


Commands::Commands()
    : hashmap{}, quit{false}, debug{false}
{
}


void Commands::mainLoop()
{
    // gets command from input and execute them
    while (quit != true)
    {
        getCommand();
        checkAndExecute();
    }
}


void Commands::clearStream()
{
    // clears commandStream
    std::stringstream().swap(commandStream);
}


void Commands::getCommand()
{
    // get a line of command from input and store as string first
    clearStream();
    commandString = readLine();
}


void Commands::invalidInput()
{
    // print "INVALID\n"
    printInvalid();
}


void Commands::checkAndExecute()
{
    // check the length and first parameter from command
    if (checkWordCount() == false)
    {
        invalidInput();
        return;
    }
    setFirstParameter();
    executeCommand();
}


bool Commands::checkWordCount()
{
    // checks word count of input is between acceptable range (1-3)
    clearStream();  // make a new stream to put the string in
    commandStream << commandString;

    std::string temp = "";
    wordCount = 0;
    // count the number of words (separated by space) in the line
    while (commandStream >> temp)
    {
        wordCount++;
    }
    // count need to be between 1 and 3
    if (wordCount < 1 || wordCount > 3)
    {
        return false;
    }
    return true;
}


void Commands::setFirstParameter()
{
    // At least one word inputed, we can use the first word to determine which
    // command to execute
    clearStream();  // reset input stream to reparse
    commandStream << commandString;
    commandStream >> parameter1;
}


void Commands::executeCommand()
{
    // execute correct command base on the first parameter
    if (parameter1 == "DEBUG")
    {
        executeDebug();
    }
    else if (debug == true && parameter1 == "LOGIN")
    {
        executeDebugLoginCount();
    }
    else if (debug == true && parameter1 == "BUCKET")
    {
        executeBucketCount();
    }
    else if (debug == true && parameter1 == "LOAD")
    {
        executeLoadFactor();
    }
    else if (debug == true && parameter1 == "MAX")
    {
        executeMaxBucketSize();
    }
    else if (parameter1 == "QUIT")
    {
        executeQuit();
    }
    else if (parameter1 == "CLEAR")
    {
        executeClear();
    }
    else if (parameter1 == "CREATE")
    {
        executeCreate();
    }
    else if (parameter1 == "LOGIN")
    {
        executeLogin();
    }
    else if (parameter1 == "REMOVE")
    {
        executeRemove();
    }
    else
    {
        invalidInput();
    }
}


void Commands::executeQuit()
{
    // quits the program
    if (wordCount == 1)  // make sure no extra parameter
    {
        quit = true;
        printLine("GOODBYE");
    }
    else
    {
        printInvalid();
    }
}


void Commands::executeClear()
{
    // clears all login from hashmap
    if (wordCount == 1)  // make sure no extra parameter
    {    
        hashmap.clear();
        printLine("CLEARED");
    }
    else
    {
        invalidInput();
    }
}


void Commands::executeCreate()
{
    // creates a new login/password if not exist
    if (wordCount != 3)  // must be 3 words
    {
        invalidInput();
        return;
    }

    commandStream >> parameter2;
    commandStream >> parameter3;

    if (hashmap.contains(parameter2) == true)  // already exists
    {
        printLine("EXISTS");
    }
    else  // add to hashmap
    {
        hashmap.add(parameter2, parameter3);
        printLine("CREATED");
    }
}


void Commands::executeLogin(bool parameterParsed)  // default=false
{
    // check login/password combination
    if (wordCount != 3)  // must be 3 word
    {
        invalidInput();
        return;
    }

    if (parameterParsed == false)  // if parameter was not stored already
    {
        commandStream >> parameter2;
        commandStream >> parameter3;
    }

    // check login/password combination is correct
    if ((hashmap.contains(parameter2) == true)
        && (hashmap.value(parameter2) == parameter3))
    {
        printLine("SUCCEEDED");
    }
    else
    {
        printLine("FAILED");
    }
}


void Commands::executeRemove()
{
    // remove a login/password from hashmap
    if (wordCount != 2)  // must be 2 words
    {
        invalidInput();
        return;
    }

    commandStream >> parameter2;

    // check if the login is in hashmap
    if (hashmap.contains(parameter2) == true)
    {
        hashmap.remove(parameter2);
        printLine("REMOVED");
    }
    else
    {
        printLine("NONEXISTENT");
    }
}


void Commands::executeDebug()
{
    // turn debug commands on/off
    if (wordCount != 2)  // 2 word command
    {
        invalidInput();
        return;
    }

    commandStream >> parameter2;
    // check second word is "ON" or "OFF"
    if ((parameter2 != "ON") && (parameter2 != "OFF"))
    {
        invalidInput();
        return;
    }    

    if (debug == true)
    {
        if (parameter2 == "OFF")
        {
            debug = false;
            printLine("OFF NOW");
        }
        else  // paramter2 == "ON"
        {
            printLine("ON ALREADY");
        }
    }
    else  // debug == false mod
    {
        if (parameter2 == "OFF")
        {
            printLine("OFF ALREADY");
        }
        else  // paramter2 == "ON"
        {
            debug = true;
            printLine("ON NOW");
        }
    }
}


void Commands::executeDebugLoginCount()
{
    // login command when in debug mode, check one extra command format
    if (wordCount == 2)
    {
        // if 2 words, then it should be "LOGIN COUNT"
        commandStream >> parameter2;
        if (parameter2 != "COUNT")
        {
            invalidInput();
            return;
        }
        printInt(hashmap.size());
    }
    else if (wordCount == 3)  // else check using the normal login funcion
    {
        commandStream >> parameter2;
        commandStream >> parameter3;
        executeLogin(true);
    }
    else
    {
        invalidInput();
    }
}


void Commands::executeBucketCount()
{
    // check format for "BUCKET COUNT"
    if (wordCount == 2)
    {
        commandStream >> parameter2;
        if (parameter2 == "COUNT")
        {
            printInt(hashmap.bucketCount());
            return;
        }
    }
    invalidInput();
    return;
}


void Commands::executeLoadFactor()
{
    // check format for "LOAD FACTOR"
    if (wordCount == 2)
    {
        commandStream >> parameter2;
        if (parameter2 == "FACTOR")
        {
            printDouble(hashmap.loadFactor());
            return;
        }
    }
    invalidInput();
    return;
}


void Commands::executeMaxBucketSize()
{
    // check format for "MAX BUCKET SIZE"
    if (wordCount == 3)
    {
        commandStream >> parameter2;
        commandStream >> parameter3;
        if ((parameter2 == "BUCKET") && (parameter3 == "SIZE"))
        {
            printInt(hashmap.maxBucketSize());
            return;
        }
    }
    invalidInput();
    return;
}
