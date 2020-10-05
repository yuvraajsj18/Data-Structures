#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename type>
class Queue
{
    private:
        type *queue;
        int front;
        int rear;
        int max_size;
        int num_elements;
    public:
        Queue(int size);
        ~Queue();

        bool isempty();
        bool isfull();
        void enqueue(type element); // throw runtime_error if queue full
        type dequeue(); // throw runtime_error if queue empty
        void display();
        type get_front(); // throw runtime_error if queue empty
        void clear();
};

#include "queue.tpp"
#endif
