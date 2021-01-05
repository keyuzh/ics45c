// EditorModel.cpp
//
// ICS 45C Fall 2020
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"

#include <algorithm>
#include <exception>

EditorModel::EditorModel()
    : currentLine{1}, currentColumn{1}, errorMsg{""}, text{}
{
    // add line 1 to vector
    text.push_back("");
}


int EditorModel::cursorLine() const
{
    return currentLine;
}


int EditorModel::cursorColumn() const
{
    return currentColumn;
}


int EditorModel::lineCount() const
{
    return text.size();
}


const std::string& EditorModel::line(int lineNumber) const
{
    return text.at(lineNumber-1);
}


const std::string& EditorModel::currentErrorMessage() const
{
    return errorMsg;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
    errorMsg = errorMessage;
}


void EditorModel::clearErrorMessage()
{
    errorMsg = "";
}


// some private helper functions
// returns the length of string at current line
int EditorModel::currentLineLength() const
{
    return lineLength(currentLine);
}

// returns the length of string in given line
const int EditorModel::lineLength(int ln) const
{
    return line(ln).length();
}

// returns the character at given line and column
char EditorModel::getChar(int ln, int col)
{
    return line(ln).at(col-1);
}

// returns the column number when the cursor is at the end of line
// (line.length() + 1)
const int EditorModel::lineEndCol(int ln) const
{
    return lineLength(ln) + 1;
}

// returns boolean value whether there is any text in editor
bool EditorModel::isEmpty()
{
    return (text.size() == 1 && line(1) == "");
}

// get a reference to string at given lineNumber
std::string& EditorModel::getline(int lineNumber)
{
    return text.at(lineNumber-1);
}


// public member functions that handles movement of cursor, adding/deleting
// characters and lines
void EditorModel::move(char dir)
{
    try
    {
        switch (dir)
        {
        case 'R':  // move right
            if (currentColumn == (currentLineLength() + 1))  // cursor at end
            {
                throw EditorException{"Already at end"};
                // throw EditorException{""};
            }
            setCursor(currentLine, currentColumn+1);
            break;

        case 'L':  // move left
            if (currentColumn == 1)  // cursor already at beginning
            {
                throw EditorException{"Already at beginning"};
            }
            setCursor(currentLine, currentColumn-1);
            break;

        case 'U':  // move up
            if (currentLine == 1)  // cursor at line 1
            {
                throw EditorException{"Already at top"};
            }
            setCursor(  // move column if necessary
                currentLine-1, 
                std::min(currentColumn, lineEndCol(currentLine-1))
                );
            break;

        case 'D':  // move down
            if (currentLine == lineCount())  // cursor at last line
            {
                throw EditorException{"Already at bottom"};
            }
            setCursor(  // move column if necessary
                currentLine+1, 
                std::min(currentColumn, lineEndCol(currentLine+1))
                );
            break;

        case 'H':  // move home, no exception necessary
            setCursor(currentLine, 1);
            break;

        case 'E':  // move end, no exception
            setCursor(currentLine, lineEndCol(currentLine));
            break;
        }
    }
    catch(const EditorException& e)
    {
        setErrorMessage(e.getReason());
        throw;
    }
}

// set the cursor postion
void EditorModel::setCursor(int ln, int col)
{
    currentLine = ln;
    currentColumn = col;
}

// insert the given character at cursor's postion, then move cursor right
void EditorModel::insert(char code)
{
    // insert char to the string
    text.at(currentLine-1).insert(currentColumn-1, 1, code);
    // move cursor right
    move('R');
}

// delete the character at the given position, returns the char deleted
char EditorModel::pop(int line, int column)
{
    // save the char for return value
    char c = getChar(line, column);
    // remove char from string
    getline(line).erase(column-1, 1);
    return c;
}

// add a newline from current cursor position
void EditorModel::newline()
{
    // reference to current line of text
    std::string& currentText = text.at(currentLine-1);
    // substr of text from current cursor position to the end
    std::string nextText = currentText.substr(currentColumn-1);

    // remove the text at current line after cursor
    currentText.erase(currentText.begin()+currentColumn-1, currentText.end());
    // make the substr the content at the next line
    text.insert(text.begin() + currentLine, nextText);

    // move cursor to beginning of next line
    setCursor(currentLine+1, 1);
}

// delete 1 char at the left of current cursor
// if cursor at col 1, current line of text is moved to prev line
// returns: {0, char} if deleted a char; {1, ''} if deleted the line
std::tuple<int, char> EditorModel::backspace()
{
    if (currentLine == 1 && currentColumn == 1)  // cursor at ln 1 col 1
    {
        throw EditorException{"Already at beginning"};
    }
    if (currentColumn != 1)  // cursor not at beginning of line, remove 1 char
    {
        char removed = pop(currentLine, currentColumn-1);
        move('L');  // move cursor left after removing
        return std::make_tuple(0, removed);
    }

    // the end position of previous line, move cursor there later
    int prevLine = currentLine - 1;
    int prevCol  = lineEndCol(currentLine-1);

    // append current line of text to prev line
    getline(currentLine-1).append(line(currentLine));

    // remove current line
    deleteLine();

    // move cursor at beginning of moved text
    setCursor(prevLine, prevCol);

    return std::make_tuple(1, 0);
}

// delete the entire current line, then move cursor accordingly
std::string EditorModel::deleteLine()
{
    if (isEmpty())  // no text in editor
    {
        throw EditorException{"Already empty"};
    }
    
    // saves the content of current line and erase it
    std::string content = line(currentLine);
    text.erase(text.begin()+currentLine-1);

    // if there was only one line in editor and erasing it makes the size 0
    if (text.size() == 0)
    {
        text.push_back("");
        setCursor(1,1);
    }
    else
    {
        int sz = static_cast<int>(text.size());  // convert size to int
        setCursor(
            std::min(currentLine, sz), 
            std::min(currentColumn, lineEndCol(std::min(currentLine, sz)))
            );
    }
    return content;
}

// insert a line to given line number
void EditorModel::addLine(int lineNumber, std::string& content)
{
    // if editor is empty, do not add additional elements into the vector
    if (isEmpty() && lineNumber == 1)
    {
        text.front() = content;
        return;
    }
    // else insert the string to given line
    text.insert(text.begin() + lineNumber - 1, content);
}
