// InteractionProcessor.cpp
//
// ICS 45C Fall 2020
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"

#include "CommandStack.hpp"


// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.
// UPDATE: added

void InteractionProcessor::run()
{
    view.refresh();

    // the stack for storing undo/redo commands
    CommandStack commandStack;

    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();

        if (interaction.type() == InteractionType::quit)
        {
            break;
        }
        else if (interaction.type() == InteractionType::undo)
        {
            try
            {
                // get last command from stack
                Command* lastCommand = commandStack.getUndoStack();
                // calls undo member function
                lastCommand->undo(model);
                // after command is undone, push it into the redo stack
                commandStack.pushRedoStack(lastCommand);
                model.clearErrorMessage();
            }
            catch (EditorException& e)
            {
                model.setErrorMessage(e.getReason());
            }
            view.refresh();
        }
        else if (interaction.type() == InteractionType::redo)
        {
            try
            {
                // get next command from stack to redo
                Command* nextCommand = commandStack.getRedoStack();
                // re-execute the command
                nextCommand->execute(model);
                // push the command back to undo stack
                commandStack.pushUndoStack(nextCommand);
                model.clearErrorMessage();
            }
            catch (EditorException& e)
            {
                model.setErrorMessage(e.getReason());
            }
            view.refresh();
        }
        else if (interaction.type() == InteractionType::command)
        {
            Command* command = interaction.command();
            try
            {
                command->execute(model);
                // push it into undo stack
                commandStack.pushUndoStack(command);
                // command in redo stack no longer accessible
                commandStack.clearRedoStack();
                model.clearErrorMessage();
            }
            catch (EditorException& e)
            {
                delete command;  // command not successfully executed
                model.setErrorMessage(e.getReason());
            }

            view.refresh();

            // Note that you'll want to be more careful about when you delete
            // commands once you implement undo and redo.  For now, since
            // neither is implemented, I've just deleted it immediately
            // after executing it.  You'll need to wait to delete it until
            // you don't need it anymore.
            // delete command;
        }
    }
}

