// InsertCharacter.hpp
// ICS45C Fall 2020 Project 4
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#ifndef INSERTCHARACTER_HPP
#define INSERTCHARACTER_HPP

#include "Command.hpp"

class InsertCharacter : public Command
{
public:
    InsertCharacter(char code);

    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

private:
    // code of the character to be inserted
    char code;

    // position where the char was inserted
    int line;
    int col;
};

#endif
