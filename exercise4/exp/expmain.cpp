// expmain.cpp
//
// Do whatever you'd like here.  This is intended to allow you to experiment
// with the code in the "app" directory or with any additional libraries
// that are part of the project, outside of the context of the main
// application or Google Test.

#include "problem3.cpp"
#include <string>


int main()
{
    LinkedList list{nullptr};

    LinkedList::Node* word3 = list.setNode("happy", nullptr);
    LinkedList::Node* word2 = list.setNode("is", word3);
    LinkedList::Node* word1 = list.setNode("Boo", word2);
    list.setHead(word1);

    list.printAll();
    list.transformEach([](const std::string& s) { return s + "!"; });
    list.printAll();


    return 0;
}

