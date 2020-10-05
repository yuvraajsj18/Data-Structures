#include "deque.h"

template <typename type>
Deque<type> :: Deque()
{
    head = tail = nullptr;
}

template <typename type>
Deque<type> :: ~Deque()
{
    while (head != nullptr)
    {
        Node<type> *temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename type>
inline bool Deque<type> :: isempty()
{
    return head == nullptr;
}

template <typename type>
void Deque<type> :: insert_front(type element)
{
    if (head == nullptr)
        head = tail = new Node<type>(element);
    else
    {
        head = new Node<type>(element, nullptr, head);
        head->next->previous = head;   
    }
}

template <typename type>
void Deque<type> :: insert_back(type element)
{
    if (head == nullptr)
        head = tail = new Node<type>(element);
    else
    {
        tail = new Node<type>(element, tail, nullptr);
        tail->previous->next = tail;   
    }
}

template <typename type>
type Deque<type> :: erase_front()
{
    if (head == nullptr)
        throw runtime_error("Underflow! Queue is empty");

    type saved_data = head->data;
    Node<type> *temp = head;

    if (head == tail)
        head = tail = nullptr;
    else
    {
        head = head->next;
        head->previous = nullptr;
    }
    
    delete temp;
    return saved_data;
}

template <typename type>
type Deque<type> :: erase_back()
{
    if (head == nullptr)
        throw runtime_error("Underflow! Queue is empty");

    type saved_data = tail->data;
    Node<type> *temp = tail;

    if (head == tail)
        head = tail = nullptr;
    else
    {
        tail = tail->previous;
        tail->next = nullptr;
    }

    delete temp;
    return saved_data;
}

template <typename type>
type Deque<type> :: front()
{
    if (head == nullptr)
        throw runtime_error("Deque is empty");
    return head->data;
}

template <typename type>
type Deque<type> :: back()
{
    if (head == nullptr)
        throw runtime_error("Deque is empty");
    return tail->data;
}

template <typename type>
int Deque<type> :: size()
{
    if (head == nullptr)
        return 0;

    Node<type> *temp = head;
    int count = 0;
    for (; temp != nullptr; temp = temp->next, count++);

    return count;
}

template <typename type>
void Deque<type> :: display()
{   
    Node<type> *temp = head;
    for (; temp != nullptr; temp = temp->next)
        cout << temp->data << " ";
    cout << "\n";
}
