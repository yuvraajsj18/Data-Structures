#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename type>
class Queue;

template <typename type>
class Node
{
    type data;
    Node<type> *next;
    friend class Queue<type>;

    public:
        Node(type data, Node<type> *next=nullptr)
        {
            this->data = data;
            this->next = next;
        }
};

template <typename type>
class Queue
{
    private:
        Node<type> *tail;
        int num_elements;
    public:
        Queue();
        ~Queue();

        bool isempty();
        void enqueue(type element);
        type dequeue(); // throw runtime_error if queue empty
        void display();
        int size();
        type get_front(); // throw runtime_error if queue empty
        void clear();
};

#include "queue.tpp"
#endif
