// CommandStack.hpp
// ICS45C Fall 2020 Project 4
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#ifndef COMMANDSTACK_HPP
#define COMMANDSTACK_HPP

#include <vector>
#include "Command.hpp"

class CommandStack
{
public:
    CommandStack() = default;
    ~CommandStack();

    // clears the stack
    void clearRedoStack();
    void clearUndoStack();

    // add an element to the undo stack (last command)
    void pushUndoStack(Command* command);

    // add an element to the redo stack (next command)
    void pushRedoStack(Command* command);

    // gets the last element in undo stack
    Command* getUndoStack();

    // gets the last element in redo stack
    Command* getRedoStack();

private:
    static std::vector<Command*> undoStack;
    static std::vector<Command*> redoStack;
};

#endif  // COMMANDSTACK_HPP