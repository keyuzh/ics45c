// BooEditTests.cpp
//
// ICS 45C Fall 2020
// Project #4: People Just Want to Play with Words
//
// Feel free to write unit tests for BooEdit here.  These are not required
// but you might find this to be a useful way to verify that various parts
// of your program are working.
//
// I've provided some tools to help you build your tests, along with four
// unit tests that demonstrate how to use what I provided.  There are also
// comments in this file to explain the techniques I'm using that are
// potentially new to you.

#include <algorithm>
#include <vector>
#include <gtest/gtest.h>
#include "BooEdit.hpp"
#include "EditorModel.hpp"
#include "InvisibleEditorView.hpp"
#include "KeypressInteractionReader.hpp"
#include "MockKeypressReader.hpp"


// A "test fixture" class is a way of writing a class that contains
// common functionality that you'd like to share amongst many of your
// tests.  To build one, you derive a class from testing::Test, which
// is part of the Google Test library.

class BooEditTests : public testing::Test
{
public:
    // If you override the SetUp() function from testing::Test, as I've
    // done here, then you're asking Google Test to call this before
    // each test runs, which lets you implement some common set-up
    // functionality.  In this case, I'm creating a "skeleton" version
    // of BooEdit that has no user interface (i.e., it doesn't draw
    // on the screen and it doesn't read its input from the keyboard).
    void SetUp() override
    {
        keypressReader = new MockKeypressReader;
        interactionReader = new KeypressInteractionReader{*keypressReader};
        view = new InvisibleEditorView;
        model = new EditorModel;
        editor = new BooEdit{*model, *view, *interactionReader};
    }


    // If you override the TearDown() function from testing::Test, then
    // you're asking Google Test to call this after each test runs.
    // What I'm doing here is destroying the things that I set up
    // before the test.
    void TearDown() override
    {
        delete editor;
        delete model;
        delete view;
        delete interactionReader;
        delete keypressReader;
    }


    // Any of the functions that are virtual in this test fixture class
    // will also be available to call within any of the test functions
    // that you associate with it.  So, the rest of these functions are
    // specifically there so you can call them in your tests.


    // CTRL('B') is a way to generate a code for a Ctrl+B that other
    // parts of this test fixture understand.
    virtual int CTRL(char c)
    {
        return -c;
    }


    // Call the run() member function when you want to run an entire
    // editor session (i.e., when you want to push a bunch of "fake"
    // keypresses through it).  What you pass to it is a vector of
    // the character codes, which you can most easily specify using
    // characters or calls to CTRL().  In fact, you don't even need to
    // create the vector by hand; C++ will infer automatically that
    // you want to build one if you just pass it an initializer list.
    // So, for example, if you write this in your test:
    //
    //     run({ 'B', 'o', 'o', CTRL('U') });
    //
    // then you're asking for your test to push four characters of
    // "fake" input through it: B, o, o, Ctrl+U.
    virtual void run(const std::vector<int>& keypressCodes)
    {
        std::vector<Keypress> keypressesToAdd;

        for (int keypressCode : keypressCodes)
        {
            if (keypressCode < 0)
            {
                keypressesToAdd.push_back(Keypress::ctrl(static_cast<char>(-keypressCode)));
            }
            else
            {
                keypressesToAdd.push_back(Keypress::normal(static_cast<char>(keypressCode)));
            }
       }

       keypressesToAdd.push_back(Keypress::ctrl('X'));

       keypressReader->addKeypresses(keypressesToAdd);
       editor->run();
    }


    // Call expectText() and pass it a vector of strings when you
    // want to verify the complete text in the editor.  The editor
    // would need to have the same number of lines of text *and*
    // the contents of every line would need to be character-for-
    // character identical.
    //
    // Once again, you can use the trick of building the vector
    // automatically with an initializer list.  This would be a
    // way of saying "I expect the editor to contain two lines of
    // text, with the first line being 'Boo' and the second line
    // being 'rocks'."
    //
    //     expectText({ "Boo", "rocks" });
    virtual void expectText(const std::vector<std::string>& lines)
    {
        ASSERT_EQ(model->lineCount(), lines.size());

        unsigned int linesToCheck = std::min(
            static_cast<size_t>(model->lineCount()),
            lines.size());

        for (unsigned int i = 0; i < linesToCheck; ++i)
        {
            EXPECT_EQ(model->line(i + 1), lines.at(i));
        }
    }


    // Call expectCursor() when you want to verify the exact position
    // (line and column) of the cursor within the editor.
    virtual void expectCursor(int line, int column)
    {
        EXPECT_EQ(line, model->cursorLine());
        EXPECT_EQ(column, model->cursorColumn());
    }


    // Call expectErrorMessage() when you want to verify that your
    // editor is displaying an error message.  There are requirements
    // in the project write-up about *when* error messages are
    // displayed, but not *what* error messages are displayed, so this
    // is a way of verifying that you're displaying an error message
    // at the appropriate time.
    virtual void expectErrorMessage()
    {
        EXPECT_GT(model->currentErrorMessage().length(), 0);
    }


    // Call expectNoErrorMessage() when you want to verify that your
    // editor is not displaying any error message.
    virtual void expectNoErrorMessage()
    {
        EXPECT_EQ(0, model->currentErrorMessage().length());
    }


private:
    MockKeypressReader* keypressReader;
    InteractionReader* interactionReader;
    EditorView* view;
    EditorModel* model;
    BooEdit* editor;
};



// Once you have a test fixture class, you use TEST_F() instead of TEST()
// when you want to write a test function that's associated with your
// test fixture class.  When you write a test this way, it "inherits"
// all of the functionality of your test fixture class (i.e., you can
// think of it being a member function in a class that inherits from
// your test fixture class), which is why I'm able to call run(),
// expectText(), and so on within each test.



TEST_F(BooEditTests, noTextAtStartup)
{
    run({ });
    expectText({ "" });
    expectCursor(1, 1);
    expectNoErrorMessage();
}


TEST_F(BooEditTests, addingOneCharacterOfTextToFirstLine)
{
    run({ 'B' });
    expectText({ "B" });
    expectCursor(1, 2);
    expectNoErrorMessage();
}


TEST_F(BooEditTests, cursorMovingLeftOnFirstLine)
{
    run({ 'B', 'o', 'o', CTRL('U') });
    expectText({ "Boo" });
    expectCursor(1, 3);
    expectNoErrorMessage();
}


TEST_F(BooEditTests, newLineAtEndOfLine)
{
    run({ 'B', 'o', 'o', CTRL('M'), 'r', 'o', 'c', 'k', 's' });
    expectText({ "Boo", "rocks" });
    expectCursor(2, 6);
    expectNoErrorMessage();
}


TEST_F(BooEditTests, cursorMovingLeftAtBeginningOfInput)
{
    run({ CTRL('U') });
    expectText({ "" });
    expectCursor(1, 1);
    expectErrorMessage();
}


// Of course, you'll want to write more of these as you go along.

// test some cursor movements
TEST_F(BooEditTests, cursorMovingRightAtBeginningOfInput)
{
    run({ CTRL('O') });
    expectText({ "" });
    expectCursor(1, 1);
    expectErrorMessage();
}

TEST_F(BooEditTests, cursorMovingUpAtBeginningOfInput)
{
    run({ CTRL('I') });
    expectText({ "" });
    expectCursor(1, 1);
    expectErrorMessage();
}

TEST_F(BooEditTests, cursorMovingDownAtBeginningOfInput)
{
    run({ CTRL('K') });
    expectText({ "" });
    expectCursor(1, 1);
    expectErrorMessage();
}

TEST_F(BooEditTests, cursorMovingRightAtFirstLine)
{
    run({ 'B', 'o', 'o', CTRL('U'),  CTRL('U'), CTRL('U'), CTRL('O') });
    expectText({ "Boo" });
    expectCursor(1, 2);
    expectNoErrorMessage();
}

TEST_F(BooEditTests, cursorMovingUp)
{
    run({ 'B', 'o', 'o', CTRL('M'), 'r', 'o' , CTRL('I')});
    expectText({ "Boo", "ro" });
    expectCursor(1, 3);
    expectNoErrorMessage();
}

TEST_F(BooEditTests, cursorMovingDown)
{
    run({ 'B', 'o', 'o', CTRL('M'), 'r', 'o' , CTRL('M'), 'a', 'b', CTRL('I'),
        CTRL('U'), CTRL('K')});
    expectText({ "Boo", "ro" , "ab"});
    expectCursor(3, 2);
    expectNoErrorMessage();
}


// test movements that will lead to error
TEST_F(BooEditTests, cursorMovingUpFromTopLine)
{
    run({ 'B', 'o', 'o', CTRL('M'), 'r', 'o' , CTRL('M'), 'a', 'b', 'c', 
        CTRL('M') , CTRL('I'), CTRL('O'), CTRL('I'), CTRL('I'), CTRL('I')});
    expectCursor(1, 2);
    expectText({ "Boo", "ro" , "abc", ""});
    expectErrorMessage();
}

TEST_F(BooEditTests, cursorMovingDownFromBottomLine)
{
    run({ 'B', 'o', 'o', CTRL('M'), 'r', 'o' , CTRL('M'), 'a', 'b', 'c', 
        CTRL('M'), CTRL('I'), CTRL('I'), CTRL('K'), CTRL('K'), CTRL('K')});
    expectCursor(4, 1);
    expectText({ "Boo", "ro" , "abc", ""});
    expectErrorMessage();
}

TEST_F(BooEditTests, cursorMovingLeftFromBeginningOfLine)
{
    run({ 'B', 'o', 'o', CTRL('M'), 'r', 'o',  CTRL('U'), CTRL('U'), CTRL('U')});
    expectCursor(2, 1);
    expectText({ "Boo", "ro" });
    expectErrorMessage();
}

TEST_F(BooEditTests, cursorMovingRightFromEndOfLine)
{
    run({ 'B', 'o', 'o', CTRL('M'), 'r', 'o', CTRL('U'), CTRL('U'), CTRL('O'), 
        CTRL('O'), CTRL('O')});
    expectText({ "Boo", "ro" });
    expectCursor(2, 3);
    expectErrorMessage();
}


// test moving cursor up and down into shorter lines
TEST_F(BooEditTests, cursorMovingUpIntoShortLine)
{
    run({ 'B', 'o', 'o', CTRL('M'), 'r', 'o', 'c', 'k', 's', CTRL('I')});
    expectText({ "Boo", "rocks" });
    expectCursor(1, 4);
    expectNoErrorMessage();
}

TEST_F(BooEditTests, cursorMovingDownIntoShortLine)
{
    run({ 'B', 'o', 'o', 'o', 'o', CTRL('M'), 'r', 'o', CTRL('I'), CTRL('O'), 
        CTRL('O'), CTRL('O'), CTRL('O'), CTRL('K')});
    expectText({ "Boooo", "ro" });
    expectCursor(2, 3);
    expectNoErrorMessage();
}


// test home and end command
TEST_F(BooEditTests, cursorMovingHome)
{
    run({ 'B', 'o', 'o', 'o', 'o', CTRL('M'), 'r', 'o', CTRL('Y')});
    expectCursor(2, 1);
    expectText({ "Boooo", "ro" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, cursorMovingHomeFromBeginning)
{
    run({ 'B', 'o', 'o', 'o', 'o', CTRL('M'), 'r', 'o', CTRL('Y'), CTRL('I'), 
        CTRL('Y')});
    expectCursor(1, 1);
    expectText({ "Boooo", "ro" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, cursorMovingEnd)
{
    run({ 'B', 'o', 'o', 'o', 'o', CTRL('M'), 'r', 'o', CTRL('I'), CTRL('P')});
    expectCursor(1, 6);
    expectText({ "Boooo", "ro" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, cursorMovingEndFromEnd)
{
    run({ 'B', 'o', 'o', 'o', 'o', CTRL('M'), 'r', 'o', CTRL('Y'), CTRL('O'), 
        CTRL('O'), CTRL('P')});
    expectCursor(2, 3);
    expectText({ "Boooo", "ro" });
    expectNoErrorMessage();
}


// test newline
TEST_F(BooEditTests, addingNewLineFromEnd)
{
    run({ 'B', 'o', 'o', 'o', 'o', CTRL('M'), 'r', 'o', 'c', 'k', 's', CTRL('J')});
    expectText({ "Boooo", "rocks", ""});
    expectCursor(3, 1);
    expectNoErrorMessage();
}

TEST_F(BooEditTests, addingNewLineFromMiddle)
{
    run({ 'B', 'o', 'o', 'o', 'o', CTRL('M'), 'r', 'o', 'c', 'k', 's', 
        CTRL('U'), CTRL('U'), CTRL('U'), CTRL('J')});
    expectCursor(3, 1);
    expectText({ "Boooo", "ro", "cks"});
    expectNoErrorMessage();
}


// test backspace
TEST_F(BooEditTests, backspaceFromBeginning)
{
    run({ CTRL('H')});
    expectCursor(1, 1);
    expectText({ ""});
    expectErrorMessage();
}

TEST_F(BooEditTests, backspaceDeletesCharacter)
{
    run({ 'B', 'o', 'o', 'o', 'o', CTRL('H') });
    expectCursor(1, 5);
    expectText({ "Booo" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, backspaceDeletesCharacterFromMiddleOfLine)
{
    run({ 'B', 'o', 'a', 'b', 'c', CTRL('U'), CTRL('U'), CTRL('H') });
    expectCursor(1, 3);
    expectText({ "Bobc" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, backspaceFromBeginningOfLine)
{
    run({ 'B', 'o', 'o', CTRL('M'), 'r', 'o', 'c', 'k', 's', CTRL('Y'), CTRL('H')});
    expectCursor(1, 4);
    expectText({ "Boorocks" });
    expectNoErrorMessage();
}


// test delete line
TEST_F(BooEditTests, deleteLineFromBeginning)
{
    run({ CTRL('D')});
    expectCursor(1, 1);
    expectText({ ""});
    expectErrorMessage();
}

TEST_F(BooEditTests, deleteFirstLine)
{
    run({ 'B', 'o', 'a', 'b', 'c', CTRL('D')});
    expectCursor(1, 1);
    expectText({ ""});
    expectNoErrorMessage();
}

TEST_F(BooEditTests, deleteLastLineOfFile)
{
    run({ 'B', 'o', 'o', 'a', 'b', 'c', CTRL('M'), 'r', 'o', CTRL('D')});
    expectCursor(1, 3);
    expectText({ "Booabc"});
    expectNoErrorMessage();
}

TEST_F(BooEditTests, deleteLineFromMiddle)
{
    run({ 'B', 'o', 'o', CTRL('M'), 'a', 'b', 'c', CTRL('M'), 'r', 'o', 
        CTRL('I'), CTRL('D')});
    expectCursor(2, 3);
    expectText({ "Boo", "ro"});
    expectNoErrorMessage();
}


// test undo
TEST_F(BooEditTests, undoInsertChar)
{
    run({ 'A', 'B', 'C', CTRL('Z') });
    expectCursor(1, 3);
    expectText({ "AB" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, undoCursorLeft)
{
    run({ 'A', 'B', 'C', CTRL('U'), CTRL('Z') });
    expectCursor(1, 4);
    expectText({ "ABC" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, undoCursorRight)
{
    run({ 'A', 'B', 'C', CTRL('U'), CTRL('O'), CTRL('Z') });
    expectCursor(1, 3);
    expectText({ "ABC" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, undoCursorUp)
{
    run({ 'A', 'B', 'C', CTRL('M'), 'B', 'o', CTRL('I'), CTRL('Z') });
    expectCursor(2, 3);
    expectText({ "ABC", "Bo" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, undoCursorDown)
{
    run({ 'A', 'B', 'C', CTRL('M'), 'B', 'o', CTRL('I'), CTRL('U'), CTRL('K'),
        CTRL('Z') });
    expectCursor(1, 2);
    expectText({ "ABC", "Bo" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, undoCursorHome)
{
    run({ 'A', 'B', 'C', CTRL('U'), CTRL('Y'), CTRL('Z') });
    expectCursor(1, 3);
    expectText({ "ABC" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, undoCursorEnd)
{
    run({ 'A', 'B', 'C', CTRL('U'), CTRL('U'), CTRL('P'), CTRL('Z') });
    expectCursor(1, 2);
    expectText({ "ABC" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, undoNewline)
{
    run({ 'A', 'B', 'C', CTRL('M'), CTRL('Z') });
    expectCursor(1, 4);
    expectText({ "ABC" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, undoNewlineWithMovingContent)
{
    run({ 'A', 'B', 'C', 'D', CTRL('U'), CTRL('U'), CTRL('M'), CTRL('Z') });
    expectCursor(1, 3);
    expectText({ "ABCD" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, undoBackspace)
{
    run({ 'A', 'B', 'C', CTRL('H'), CTRL('Z') });
    expectCursor(1, 4);
    expectText({ "ABC" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, undoBackspaceAtBeginningOfLine)
{
    run({'A', 'B', 'C', CTRL('M'), 'B', 'o', CTRL('Y'), CTRL('H'), CTRL('Z')});
    expectCursor(2, 1);
    expectText({ "ABC", "Bo" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, undoDeleteLine)
{
    run({ 'A', 'B', 'C', CTRL('D'), CTRL('Z') });
    expectCursor(1, 4);
    expectText({ "ABC" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, undoDeleteLineWithMultipleLines)
{
    run({ 'A', 'B', 'C',  CTRL('M'), 'B', 'o', CTRL('I'), CTRL('D'), CTRL('Z') });
    expectCursor(1, 3);
    expectText({ "ABC", "Bo" });
    expectNoErrorMessage();
}


// test redo
TEST_F(BooEditTests, redoInsertChar)
{
    run({ 'A', 'B', 'C', CTRL('Z'), CTRL('A')});
    expectCursor(1, 4);
    expectText({ "ABC" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, redoCursorLeft)
{
    run({ 'A', 'B', 'C', CTRL('U'), CTRL('Z'), CTRL('A')});
    expectCursor(1, 3);
    expectText({ "ABC" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, redoCursorRight)
{
    run({ 'A', 'B', 'C', CTRL('U'), CTRL('O'), CTRL('Z'), CTRL('A') });
    expectCursor(1, 4);
    expectText({ "ABC" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, redoCursorUp)
{
    run({ 'A', 'B', 'C', CTRL('M'), 'B', 'o', CTRL('I'), CTRL('Z'), CTRL('A')});
    expectCursor(1, 3);
    expectText({ "ABC", "Bo" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, redoCursorDown)
{
    run({ 'A', 'B', 'C', CTRL('M'), 'B', 'o', CTRL('I'), CTRL('U'), CTRL('K'),
        CTRL('Z'), CTRL('A') });
    expectCursor(2, 2);
    expectText({ "ABC", "Bo" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, redoCursorHome)
{
    run({ 'A', 'B', 'C', CTRL('U'), CTRL('Y'), CTRL('Z'), CTRL('A') });
    expectCursor(1, 1);
    expectText({ "ABC" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, redoCursorEnd)
{
    run({ 'A', 'B', 'C', CTRL('U'), CTRL('U'), CTRL('P'), CTRL('Z'), CTRL('A')});
    expectCursor(1, 4);
    expectText({ "ABC" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, redoNewline)
{
    run({ 'A', 'B', 'C', CTRL('M'), CTRL('Z'), CTRL('A') });
    expectCursor(2, 1);
    expectText({ "ABC", "" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, redoNewlineWithMovingContent)
{
    run({ 'A', 'B', 'C', 'D', CTRL('U'), CTRL('U'), CTRL('M'), CTRL('Z'), CTRL('A')});
    expectCursor(2, 1);
    expectText({ "AB", "CD" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, redoBackspace)
{
    run({ 'A', 'B', 'C', CTRL('H'), CTRL('Z'), CTRL('A') });
    expectCursor(1, 3);
    expectText({ "AB" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, redoBackspaceAtBeginningOfLine)
{
    run({'A', 'B', 'C', CTRL('M'), 'B', 'o', CTRL('Y'), CTRL('H'), CTRL('Z'), CTRL('A')});
    expectCursor(1, 4);
    expectText({ "ABCBo" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, redoDeleteLine)
{
    run({ 'A', 'B', 'C', CTRL('D'), CTRL('Z'), CTRL('A') });
    expectCursor(1, 1);
    expectText({ "" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, redoDeleteLineWithMultipleLines)
{
    run({ 'A', 'B', 'C', CTRL('M'), 'B', 'o', CTRL('I'), CTRL('D'), CTRL('Z'), CTRL('A') });
    expectCursor(1, 3);
    expectText({ "Bo" });
    expectNoErrorMessage();
}

TEST_F(BooEditTests, multipleUndoAndRedo)
{
    run({ 'A', 'B', 'C', CTRL('M'), 'D', 'E', CTRL('Z'), CTRL('Z'), CTRL('Z'),
        CTRL('A'), CTRL('A')});
    expectCursor(2, 2);
    expectText({ "ABC", "D" });
    expectNoErrorMessage();
}

