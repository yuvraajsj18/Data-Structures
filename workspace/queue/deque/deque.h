#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename type>
class Deque;

template <typename type>
class Node
{
    type data;
    Node<type> *previous;
    Node<type> *next;
    friend class Deque<type>;

    public:
        Node(type data, Node<type> *previous = nullptr, Node<type> *next = nullptr)
        {
            this->data = data;
            this->previous = previous;
            this->next = next;
        }
};

template <typename type>
class Deque
{
    private:
        Node<type> *head;
        Node<type> *tail;
    
    public:
        Deque();
        ~Deque();

        inline bool isempty();
        void insert_front(type element);
        void insert_back(type element);
        type erase_front(); // throw runtime_error if underflow
        type erase_back(); // throw runtime_error if underflow
        type front();
        type back();
        int size();
        void display();
};

#include "deque.tpp"
#endif



