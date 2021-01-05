// MoveCursor.hpp
// ICS45C Fall 2020 Project 4
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#ifndef MOVECURSOR_HPP
#define MOVECURSOR_HPP

#include "Command.hpp"

class MoveCursor : public Command
{
public:
    MoveCursor(char dir);

    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

private:
    // direction to move
    char dir;
    // stores the position of cursor before movement
    int prevLine;
    int prevCol;
};

#endif
