// LineManipulation.hpp
// ICS45C Fall 2020 Project 4
// Name: Keyu Zhang
// ID: 19898090
// UCINetID: keyuz4

#ifndef LINEMANIPULATION_HPP
#define LINEMANIPULATION_HPP

#include <string>
#include <tuple>
#include "Command.hpp"

class LineManipulation : public Command
{
public:
    LineManipulation() = default;
};

class NewLine : public LineManipulation
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
};


class Backspace : public LineManipulation
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

private:
    // contains the type of action executed by backspace
    // int == 0 if removed a char; char contains the code removed
    // int == 1 if deleted a line
    std::tuple<int, char> removed;
};


class DeleteLine : public LineManipulation
{
public:
    DeleteLine() = default;
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
private:
    // stores the position of cursor before deleting
    int ln;
    int col;
    // stores the content of the line deleted
    std::string lineContent;
};

#endif
