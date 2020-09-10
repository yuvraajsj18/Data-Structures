#include "stack.h"

template <typename type>
Stack<type> :: Stack()
{
    top = NULL;
    count = 0;
}

template <typename type>
Stack<type> :: ~Stack()
{
    while (top)
    {
        Node<type>* temp = top;
        top = top -> next;
        delete temp;
    }
}

template <typename type>
bool Stack<type> :: is_empty() const
{
    return top == NULL;
}

template <typename type>
int Stack<type> :: size() const
{
    return count;
}

template <typename type>
type Stack<type> :: get_top_element() const
{
    if (!top)
    {
        throw runtime_error("Stack Underflow!!\n");
    }
    return top -> data;
}

template <typename type>
void Stack<type> :: push(const type element)
{
    top = new Node<type>(element, top);
    count++;
}

template <typename type>
type Stack<type> :: pop()
{
    if (!top)
    {
        throw runtime_error("Stack Underflow!!\n");
    }
    type data = top -> data;
    Node<type> *temp = top;
    top = top -> next;
    delete temp;

    count--;
    return data;
}

template <typename type>
void Stack<type> :: display()
{
    Node<type> *temp = top;
    while(temp)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

template <typename type>
void Stack<type> :: clear()
{
    while(top)
    {
        this -> pop();
    }
    top = NULL;
    count = 0;
}

