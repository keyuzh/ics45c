// InsertCharacter.cpp
// ICS45C Fall 2020 Project 4
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#include "InsertCharacter.hpp"

InsertCharacter::InsertCharacter(char code)
    : code{code}
{
}

void InsertCharacter::execute(EditorModel& model)
{
    // save the position of cursor before insertion
    line = model.cursorLine();
    col = model.cursorColumn();
    model.insert(code);
}

void InsertCharacter::undo(EditorModel& model)
{
    // delete the char at (line, col) and move cursor back to that postion
    model.pop(line, col);
    model.setCursor(line, col);
}
