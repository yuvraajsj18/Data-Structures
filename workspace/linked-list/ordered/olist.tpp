#include "olist.h"

template <typename type>
Olist<type> :: Olist()
{
    head = nullptr;
}

template <typename type>
Olist<type> :: ~Olist()
{
    while (head != nullptr)
    {
        Node<type> *temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename type>
bool Olist<type> :: isempty()
{
    return head == nullptr;
}

template <typename type>
void Olist<type> :: insert(type element)
{
    if (head == nullptr)
        head = new Node<type>(element);
    else if (element < head->data)
        head = new Node<type>(element, head);
    else
    {
        Node<type> *temp = head;
        while (temp->next != nullptr && element > temp->next->data)
            temp = temp->next;
       
        temp->next = new Node<type>(element, temp->next);
        
    }
}

template <typename type>
void Olist<type> :: delete_node(type element)
{
    if (head == nullptr)
        throw runtime_error("Underflow! list is empty");

    if (head->next == nullptr)
    {
        if (head->data == element)
        {
            delete head;
            head = nullptr;
        }
        else 
            throw runtime_error("Element not found");
    }
    else if (head->data == element)
    {
        Node<type> *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        Node<type> *pred = head;
        Node<type> *temp = head->next;
        while (temp != nullptr && temp->data != element)
        {
            temp = temp->next;
            pred = pred->next;
        }
        if (temp != nullptr)
        {
            pred->next = temp->next;
            delete temp;
        }
        else 
            throw runtime_error("Element not found");
    }
}

template <typename type>
bool Olist<type> :: search(type element)
{
    if (head == nullptr)
        return false;
    
    Node<type> *temp = head;
    for (; temp != nullptr && temp->data != element; temp=temp->next);
    if (temp == nullptr)
        return false;
    
    return true;
}

template <typename type>
void Olist<type> :: merge(Olist<type> &l1, Olist<type> &l2)
{
    if (l2.head == nullptr)
        return;

    Node<type> *temp = l2.head;
    for (; temp != nullptr; temp=temp->next)
        l1.insert(temp->data);
}

template <typename type>
void Olist<type> :: display()
{
    if (head == nullptr)
        cout << "Ordered list is empty\n";
    else
    {
        Node<type> *temp = head;
        for (; temp != nullptr; temp=temp->next)
            cout << temp->data << " ";
        cout << endl;   
    }
}


