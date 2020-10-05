#include "queue.h"

template <typename type>
Queue<type> :: Queue(int size)
{
    queue = new type[size];
    front = rear = -1;
    max_size = size;
    num_elements = 0;
}

template <typename type>
Queue<type> :: ~Queue()
{
    delete[] queue;
}

template <typename type>
bool Queue<type> :: isempty()
{
    return num_elements == 0;
}

template <typename type>
bool Queue<type> :: isfull()
{
    return num_elements == max_size;
}

template <typename type>
void Queue<type> :: enqueue(type element)
{
    // check for overflow
    if (isfull())
        throw runtime_error("Overflow! queue is full");
    
    if (front == -1)    // if first entry
        front = 0;
    
    // find rear for circular array
    rear = (rear + 1) % max_size;
    queue[rear] = element;
    num_elements++;
}

template <typename type>
type Queue<type> :: dequeue()
{
    if (isempty())
        throw runtime_error("Underflow! queue is empty");

    type saved_front = queue[front];

    if (front == rear)  // if one element
        front = rear = -1;
    else 
        front = (front + 1) % max_size; // update front

    num_elements--;
    return saved_front;
}

template <typename type>
void Queue<type> :: display()
{
    if (isempty())
        return;

    for (int i = front; i != rear; i = (i + 1) % max_size)
        cout << queue[i] << " ";
    cout << queue[rear];
    cout << "\n";
}

template <typename type>
type Queue<type> :: get_front()
{
    if (isempty())
        throw runtime_error("Queue is empty");
    
    return queue[front];
}

template <typename type>
void Queue<type> :: clear()
{
    delete[] queue;
    front = rear = -1;
    num_elements = 0;
    queue = new type[max_size];
}
