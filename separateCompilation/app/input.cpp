// input.cpp
//
// ICS 45C Fall 2020
// Code Example
//
// Based on the technique discussed on the web page accompanying this
// code example, these are the definitions of our input-reading
// functions -- the ones declared in "input.hpp".
//
// The compiler will compile this source file in the absence of the
// others, generating an object file "input.cpp.o" as a result.
// "input.cpp.o" will contain the compiled version of these functions,
// and nothing else.


// It's generally good practice to include the header file that
// corresponds to each source file, though, technically, it's not
// necessary in this case.  It wil be very important when we start
// implementing classes a little later in the course, though.  For
// this reason, I'm including "input.hpp" here.
//
// Note, too, that I included <iostream> here, but I didn't include
// it in "input.hpp".  That's because "input.hpp" didn't discuss
// the names of anything declared in <iostream>.  Our use of
// <iostream> is an implementation detail, not part of the "interface"
// of this source file, so we only need to include it here.

#include <iostream>
#include <limits>
#include "input.hpp"


int readInt()
{
    int value;

    std::cin >> value;

    // This is a fancy-looking way of saying "Keep throwing away
    // characters until you see a newline character."  We need
    // to tell std::cin.ignore() how many characters to throw away,
    // but we don't know ahead of time how many it might be, so we're
    // instead passing the maximum possible size of an input stream,
    // which is probably many, many more than it would ever need to be.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return value;
}


std::string readName()
{
    std::string name;

    std::getline(std::cin, name);

    return name;
}

