// CommandStack.cpp
// ICS45C Fall 2020 Project 4
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#include "CommandStack.hpp"
#include "EditorException.hpp"

std::vector<Command*> CommandStack::undoStack{};
std::vector<Command*> CommandStack::redoStack{};

namespace
{
    // gets the top element from stack
    Command* getTopStack(std::vector<Command*>& stack)
    {
        if (stack.empty())
        {
            // we need some kind of exception here but the example
            // program is not displaying any error messages, so we throw
            // an exception with empty error message
            // throw EditorException{"No more command to Undo/Redo"};
            throw EditorException{""};  
        }
        Command* last = stack.back();
        stack.pop_back();
        return last;
    }

    // delete all command in the stack
    void deallocateStack(std::vector<Command*>& stack)
    {
        for (Command* i : stack)
        {
            delete i;
        }
    }
}


CommandStack::~CommandStack()
{
    // deallocate both stacks
    clearRedoStack();
    clearUndoStack();
}

void CommandStack::clearRedoStack()
{
    deallocateStack(redoStack);
    redoStack.clear();
}

void CommandStack::clearUndoStack()
{
    deallocateStack(undoStack);
    undoStack.clear();
}

// push an element into stack
void CommandStack::pushUndoStack(Command* command)
{
    undoStack.push_back(command);
}

void CommandStack::pushRedoStack(Command* command)
{
    redoStack.push_back(command);
}

// get element from top of stack
Command* CommandStack::getUndoStack()
{
    return getTopStack(undoStack);
}

Command* CommandStack::getRedoStack()
{
    return getTopStack(redoStack);
}
