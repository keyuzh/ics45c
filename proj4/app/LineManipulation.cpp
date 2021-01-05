// LineManipulation.cpp
// ICS45C Fall 2020 Project 4
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#include "LineManipulation.hpp"

void NewLine::execute(EditorModel& model)
{
    model.newline();
}

void NewLine::undo(EditorModel& model)
{
    // reverse of newline is backspace
    model.backspace();
}


void Backspace::execute(EditorModel& model)
{
    // save char for undo
    removed = model.backspace();
}

void Backspace::undo(EditorModel& model)
{
    if (std::get<int>(removed) == 0)  // removed a char
    {
        // add the char back in
        model.insert(std::get<char>(removed));
    }
    else  // removed a newline
    {
        model.newline();
    }
}


void DeleteLine::execute(EditorModel& model)
{
    // save cursor position and content for undo
    ln = model.cursorLine();
    col = model.cursorColumn();
    lineContent = model.deleteLine();
}

void DeleteLine::undo(EditorModel& model)
{
    model.addLine(ln, lineContent);
    model.setCursor(ln, col);
}
