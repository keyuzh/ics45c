// input.hpp
//
// ICS 45C Fall 2020
// Code Example
//
// Based on the principles discussed in this example's web lesson (in short,
// header files contain declarations but not definitions), this header file
// contains the declaration of functions that can be used to read input.


// The #ifndef/#define/#endif technique is used to ensure that the same
// header file is not included more than once in the same source file.
// Words that begin with the "#" character are meant for the preprocessor,
// which reads each source file before the compiler does.  The preprocessor
// does some simple things -- makes macro replacements, eliminates code
// under certain conditions (so, say, you can have a file that contains
// certain code that is compiled only when the target is Windows and other
// code that is compiled only when the target is Linux).  Its commands
// are called "preprocessor directives"; those are the things that start
// with a "#" character.
//
// In this case, we have some cryptic-looking syntax, but here's how it
// reads in English:
//
//   "If you haven't seen INPUT_HPP before, make a note of the fact that
//    you've seen INPUT_HPP, so that if you see it again, you'll notice.
//    Then, go ahead and include all of the stuff in this file, up to
//    the end."
//
// Note the #endif at the end of the file; it is the end of the block that
// begins with #ifndef.
//
// The effect of this is that the contents of this file will only ever be
// included once within a source file; a subsequent attempt to include it
// will cause everything in the file to be ignored, since INPUT_HPP will
// have been seen once already.
//
// The name INPUT_HPP is chosen somewhat arbitrarily, but the goal is to
// make sure that it's globally unique.  One way to make this likely is
// to match the name of the macro to the name of the header file, the way
// we've done here.  (In much larger and more complex projects, that may
// not be good enough, as filenames may not be unique.  But, for our
// purposes in this course, we won't have the problem of having more than
// one file with the same name.)

#ifndef INPUT_HPP
#define INPUT_HPP

// Header files sometimes need to include other header files, and that's
// fine.  The reasoning is this: If you were to include "input.hpp", its
// contents would only make sense if you had already included <string>
// (because we use "std::string" below).  If we just have "input.hpp"
// include <string> itself, then this makes it impossible to do things
// wrong; the alternative is that someone would have to remember to
// include <string> before including "input.hpp", the kind of knowledge
// that would be impossible to keep track of in a large program.
#include <string>



// readInt() reads an integer from the standard input
int readInt();

// readName() reads a name from the standard input
std::string readName();



#endif

