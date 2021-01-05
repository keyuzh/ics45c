#include <string>

void LinkedList::transformEach(std::function<std::string(std::string)> f)
{
    Node* current = head;
    while (current != nullptr)
    {
        current->value = f(current->value);
        current = current->next;
    }
    
}
