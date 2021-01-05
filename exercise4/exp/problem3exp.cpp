#include <string>
#include <iostream>

class LinkedList
{
public:
    struct Node
    {
        std::string value;
        Node* next;
    };

    Node* head;
public:
    LinkedList(Node* newHead);
    void transformEach(std::function<std::string(std::string)> f);
    LinkedList::Node* setNode(std::string newvalue, Node* newnext);
    void setHead(Node* newHead);
    void printAll();
};


void LinkedList::transformEach(std::function<std::string(std::string)> f)
{
    Node* current = head;
    while (current != nullptr)
    {
        current->value = f(current->value);
        current = current->next;
    }
    
}

LinkedList::LinkedList(Node* newHead)
          : head{newHead}
{
       
}

LinkedList::Node* LinkedList::setNode(std::string newvalue, Node* newnext)
{
    LinkedList::Node* newNode = new Node{newvalue, newnext};
    return newNode;
}

void LinkedList::setHead(Node* newHead)
{
    head = newHead;
}

void LinkedList::printAll()
{
    Node* current = head;
    while (current != nullptr)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
    
}