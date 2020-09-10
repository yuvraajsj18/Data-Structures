#include "slist.h"

// member functions of Slist

template <typename type>
Slist<type> :: Slist()
{
    head = tail = NULL; // start with nothing in list
}

template <typename type>
Slist<type> :: ~Slist()
{
    while (!head)   // while not empty
    {
        Node<type> *temp = head;  // save head in temp
        delete head;    // delete head
        head = temp -> next;    // move head ahead using temp
    }
}


template <typename type>
bool Slist<type> :: is_empty()
{
    return head == NULL;    // head null means empty
}


template <typename type>
void Slist<type> :: add_head(type element)
{
    head = new Node<type>(element, head);     // make new head node and link previos head to new head's next
    if (!tail)
    {
        tail = head;    // if tail is NULL make it equal to head otherwise left unchanged
    }
}

template <typename type>
void Slist<type> :: add_tail(type element)
{
    if (tail)
    {
        Node<type> *new_tail_node = new Node<type>(element);
        tail -> next = new_tail_node;  
        tail = tail -> next; 
    }
    else
    {
        head = tail = new Node<type>(element);   
    }
}

template <typename type>
type Slist<type> :: delete_head()
{
    type data = head -> data;
    Node<type> *temp = head;
    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        head = head -> next;   
    }
    delete temp;
    return data;
}

template <typename type>
type Slist<type> :: delete_tail()
{
    type data = tail -> data;
    if (head == tail)
    {
        delete tail;
        head = tail = NULL;   
    }
    else
    {
        Node<type> *temp;
        for (temp = head; temp -> next != tail; temp = temp -> next);

        delete tail;
        tail = temp;
        tail -> next = NULL;   
    }

    return data;
}

template <typename type>
void Slist<type> :: delete_node(type element)
{
    if (head != NULL)
    {
        if (head == tail && element == head -> data)
        {
            delete head;
            head = tail = NULL;
        }
        else if (element == head -> data)
        {
            Node<type> *temp = head;
            head = head -> next;
            delete temp;
        }
        else
        {
            Node<type> *pred, *temp;
            for (pred = head, temp = head -> next; temp != NULL && temp -> data != element; pred = pred->next, temp=temp->next);

            if (temp != NULL)
            {
                pred -> next = temp -> next;
                if (temp == tail)
                {
                    tail = pred;
                }
                delete temp;
            }
        }
        
    }
}

template <typename type>
bool Slist<type> :: search(type element)
{
    Node<type> *temp;
    for (temp = head; temp != NULL && temp -> data != element; temp = temp -> next);
    return (temp != NULL);
}

template <typename type>
int Slist<type> :: count_node()
{
    int count = 0;
    Node<type> *temp;
    temp = head;
    while (temp != NULL)
    {
        temp = temp -> next;
        count++;
    }

    return count;
}

template <typename type>
void Slist<type> :: display()
{
    if (is_empty())
    {
        cout << "List is empty" << endl;
        return;
    }
    Node<type> *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


template <typename type>
void Slist<type> :: reverse()
{
    if (head == NULL)
        return;

    Node<type> *currentNode, *nextNode, *previousNode;  // r, q, s

    currentNode = NULL;
    nextNode = head;

    while (nextNode != NULL)
    {
        previousNode = currentNode;
        currentNode = nextNode;
        nextNode = nextNode -> next;
        currentNode -> next = previousNode;
    }

    head = currentNode;

    // reassign tail
    Node<type> *temp = head;
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }

    tail = temp;
}

template <typename type>
void Slist<type> :: concat(Slist<type> &s1, Slist<type> &s2)
{
    Node<type> *p = s1.head;
    Node<type> *q = s2.head;
    head = p;
    while (p-> next != NULL)
    {
        p = p -> next;
    }
    p -> next = q;
}

template <typename type>
Slist<type> Slist<type> :: operator+(Slist<type> &s)
{
    Slist<type> newList;
    Node<type> *temp = head;

    while(temp != NULL)
    {
        newList.add_tail(temp -> data);
        temp = temp -> next;
    }
    temp = s.head;
    while(temp != NULL)
    {
        newList.add_tail(temp -> data);
        temp = temp -> next;
    }

    return newList;
}

template <typename type>
Slist<type>& Slist<type> :: operator=(const Slist<type> &s)
{
    Node<type> *temp;
    while (!is_empty())
    {
        temp = head -> next;
        delete head;
        head = temp;
    }
    temp = s.head;
    head = s.head;
    while (temp != NULL)
    {
        add_tail(temp -> info);
        temp = temp -> next;
    }

    return *this;
}

