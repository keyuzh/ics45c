// MoveCursor.cpp
// ICS45C Fall 2020 Project 4
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#include "MoveCursor.hpp"

MoveCursor::MoveCursor(char dir)
    : dir{dir}
{
}

void MoveCursor::execute(EditorModel& model)
{
    prevLine = model.cursorLine();
    prevCol = model.cursorColumn();
    model.move(dir);
}

void MoveCursor::undo(EditorModel& model)
{
    // set the cursor to previous position
    model.setCursor(prevLine, prevCol);
}
