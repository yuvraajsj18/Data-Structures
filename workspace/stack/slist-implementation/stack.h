#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename type>
class Stack;

template <typename type>
class Node
{
    private:
        type data;
        Node<type>* next;
        friend class Stack<type>;
    public:

        Node(type data, Node<type>* next = NULL)
        {
            this -> data = data;
            this -> next = next;
        }
};

template <typename type>
class Stack
{
    private:
        Node<type>* top;
        int count;   // number of elements

    public:
        Stack();
        ~Stack();

        bool is_empty() const;
        int size() const;   
        type get_top_element() const;   // throw STACK UNDERFLOW
        void push(const type element);
        type pop(); // throw STACK UNDERFLOW
        void display();
        void clear();
};

#include "stack.tpp"
#endif
