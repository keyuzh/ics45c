// KeypressInteractionReader.cpp
//
// ICS 45C Fall 2020
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE

#include "KeypressInteractionReader.hpp"
#include "MoveCursor.hpp"
#include "InsertCharacter.hpp"
#include "LineManipulation.hpp"

// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

Interaction KeypressInteractionReader::nextInteraction()
{
    while (true)
    {
        Keypress keypress = keypressReader.nextKeypress();

        if (keypress.ctrl())
        {
            // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

            switch (keypress.code())
            {
            case 'X':
                return Interaction::quit();
                break;

            case 'O':  // move right
                return Interaction::command(new MoveCursor{'R'});
                break;

            case 'U':  // move left
                return Interaction::command(new MoveCursor{'L'});
                break;

            case 'I':  // move up
                return Interaction::command(new MoveCursor{'U'});
                break;

            case 'K':  // move down
                return Interaction::command(new MoveCursor{'D'});
                break;

            case 'Z':  // undo
                return Interaction::undo();
                break;

            case 'A':  // redo
                return Interaction::redo();
                break;

            case 'J':  // add newline
            case 'M':
                return Interaction::command(new NewLine);
                break;

            case 'H':  // backspace
                return Interaction::command(new Backspace);
                break;

            case 'Y':  // move home
                return Interaction::command(new MoveCursor('H'));
                break;

            case 'P':  // move end
                return Interaction::command(new MoveCursor('E'));
                break;
                
            case 'D':  // delete line
                return Interaction::command(new DeleteLine);
                break;
            }
        }
        else
        {
            // The user pressed a normal key (e.g., 'h') without holding
            // down Ctrl; react accordingly
            return Interaction::command(new InsertCharacter{keypress.code()});
        }
    }
}

