#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename type, int size>
class Stack
{
    private:
        type* stack; // stack is a dynamically allocated array that will contains all our elements.
        int top;    // index of top element in stack

    public:
        Stack();
        ~Stack();

        bool is_empty();    // Return true if stack is empty, false otherwise.
        void push(type element);    // insert 'element' at the top of stack, if not overflow
        type pop();     // remove element at the top of stack if not underflow
        void display();     // print all elements in stack to console 
        type get_top_element();     // returns the top element
        void clear();       // remove all elements in the stack and reset top.
        void reverse();
};

#include "stack.tpp"

#endif