#include "clist.h"

template <typename type>
Clist<type> :: Clist()
{
    tail = nullptr;
}

template <typename type>
Clist<type> :: ~Clist()
{
    Node<type> *temp = tail->next;
    while (temp != tail)
    {
        Node<type> *temp1 = temp;
        temp = temp->next;
        delete temp1;
    }
    delete tail;
}

template <typename type>
bool Clist<type> :: isempty()
{
    return tail == nullptr;
}

template <typename type>
void Clist<type> :: add_head(type element)
{
    if (tail == nullptr)
    {
        tail = new Node<type>(element);
        tail->next = tail; 
    }
    else
    {
        tail->next = new Node<type>(element, tail->next);
    }
}

template <typename type>
void Clist<type> :: add_tail(type element)
{
    if (tail == nullptr)
    {
        tail = new Node<type>(element);
        tail->next = tail;
    }
    else
    {
        tail->next = new Node<type>(element, tail->next);
        tail = tail->next;
    }
}

template <typename type>
type Clist<type> :: delete_head()
{
    if (tail == nullptr)
        throw runtime_error("Underflow!! List is empty.");

    type save_data = tail->next->data;
    Node<type> *temp_head = tail->next;
    if (tail == tail->next)
        tail = nullptr;
    else
        tail->next = temp_head->next;   
    
    delete temp_head;
    return save_data;
}

template <typename type>
type Clist<type> :: delete_tail()
{
    if (tail == nullptr)
        throw runtime_error("Underflow!! List is empty");
    
    type save_data = tail->data;
    if (tail == tail->next)
    {
        delete tail;
        tail = nullptr;
    }
    else
    {
        Node<type> *temp = tail->next;
        for(; temp->next != tail; temp = temp->next);
        temp->next = tail->next;
        delete tail;
        tail = temp;
    }

    return save_data;
}

template <typename type>
void Clist<type> :: delete_node(type element)
{
    if (tail == nullptr)
        throw runtime_error("Underflow!! List is empty.");

    if (tail == tail->next)
    {
        if (tail->data == element)
        {
            delete tail;
            tail = nullptr; 
        }
        else
            throw runtime_error("Element not found!!");
    }
    else if (tail->data == element)
    {
        Node<type> *temp = tail->next;
        for (; temp->next != tail; temp=temp->next);
        temp->next = tail->next;
        delete tail;
        tail = temp;
    }
    else
    {
        Node<type> *temp = tail->next;
        Node<type> *pred = tail;
        for (; temp != tail && temp->data != element; temp=temp->next, pred=pred->next);
        
        if (temp == tail)
            throw runtime_error("Element not found!!");
    
        pred->next = temp->next;
        delete temp;
    }
}

template <typename type>
bool Clist<type> :: search(type element)
{
    if (tail != nullptr && tail->data == element)
        return true;
    else if (tail != nullptr)
    {
        Node<type> *temp = tail->next;
        for (; temp != tail && temp->data != element; temp=temp->next);
        if (temp != tail)
            return true;
    }
    return false;
}

template <typename type>
int Clist<type> :: count_node()
{
    if (tail == nullptr)
        return 0;

    int count = 1;  // there is tail at least
    Node<type> *temp = tail->next;
    for (; temp != tail; temp=temp->next, count++);

    return count;
}

template <typename type>
void Clist<type> :: display()
{
    if (tail == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    Node<type> *temp = tail->next;
    while (temp != tail)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << tail->data << endl;
}

template <typename type>
void Clist<type> :: reverse()
{
    if (tail == nullptr || tail == tail->next)
        return;
    
    Node<type> *newTail = tail->next;
    Node<type> *previousNode;
    Node<type> *currentNode = tail;
    Node<type> *nextNode = tail->next;

    do
    {
        previousNode = currentNode;
        currentNode = nextNode;
        nextNode = nextNode->next;
        // change pointer of current
        currentNode->next = previousNode;
    } while (nextNode != newTail);

    tail = newTail;
}
