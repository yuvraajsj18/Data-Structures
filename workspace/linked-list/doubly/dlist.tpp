#include "dlist.h"

template <typename type>
Dlist<type> :: Dlist()
{
    head = tail = nullptr;
}

template <typename type>
Dlist<type> :: ~Dlist()
{
    while (head != nullptr)
    {
        Node<type> *temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename type>
bool Dlist<type> :: isempty()
{
    return head == nullptr;
}

template <typename type>
void Dlist<type> :: add_head(type element)
{
    if (head == nullptr)
    {
        head = tail = new Node<type>(element);
    }
    else
    {
        head = new Node<type>(element, nullptr, head);
        head -> next -> previous = head;
    }
}

template <typename type>
void Dlist<type> :: add_tail(type element)
{
    if (tail == nullptr)
    {
        head = tail = new Node<type>(element);
    }
    else
    {
        tail = new Node<type>(element, tail, nullptr);
        tail->previous->next = tail;   
    }
}

template <typename type>
type Dlist<type> :: delete_head()
{
    if (head == nullptr)
        throw runtime_error("Underflow!! List is empty.");
    
    type save_data = head->data;
    Node<type> *temp_head = head;

    if (head == tail)   // one node only
    {
        head = tail = nullptr;
    }
    else
    {
        head = head->next;  // update head
        head->previous = nullptr;   // change new head;s previous from old head to nullptr
    }
    
    delete temp_head;

    return save_data;
}

template <typename type>
type Dlist<type> :: delete_tail()
{
    if (tail == nullptr)
        throw runtime_error("Underflow!! List is empty.");

    type save_data = tail->data;
    Node<type> *temp_tail = tail;

    if (head == tail)
    {
        head = tail = nullptr;
    }
    else
    {
        tail = tail->previous;
        tail->next = nullptr;   
    }

    delete temp_tail;

    return save_data;
}

template <typename type>
void Dlist<type> :: delete_node(type element)
{
    if (head == nullptr)
        throw runtime_error("Underflow!! List is empty.");
    
    if (head == tail)
    {
        if (element == head->data)
        {
            delete head;
            head = tail = nullptr;
        }
        else
            throw runtime_error("Element not found");
    }
    else if (head->data == element)
    {
        Node<type> *temp_node = head;
        head = head->next;
        head->previous = nullptr;
        delete temp_node;
    }
    else
    {
        Node<type> *temp_node = head -> next;
        for (; temp_node != nullptr && temp_node->data != element; temp_node = temp_node->next);
        
        if (temp_node == nullptr)
            throw runtime_error("Element Not found.");
        
        if (temp_node == tail)
        {
            tail = tail->previous;
            tail->next = nullptr;
        }
        else
        {
            temp_node->previous->next = temp_node->next;
            temp_node->next->previous = temp_node->previous;
        }
        delete temp_node;
    }
}

template <typename type>
bool Dlist<type> :: search(type element)
{   
    Node<type> *temp_node = head;
    for (; temp_node != nullptr && temp_node->data != element; temp_node = temp_node->next);

    if (temp_node == nullptr)
        return false;
    
    return true;
}

template <typename type>
int Dlist<type> :: count_node()
{
    int count = 0;
    for (Node<type>*temp=head; temp != nullptr; temp=temp->next, count++);
    return count;
}

template <typename type>
void Dlist<type> :: display()
{
    Node<type> *temp_node = head;
    while (temp_node != nullptr)
    {
        cout << temp_node->data <<  " ";
        temp_node = temp_node->next;
    }
    cout << endl;
}

template <typename type>
void Dlist<type> :: reverse()
{
    if (head == nullptr || head == tail)    // one or no element
        return;

    Node<type> *previousNode;
    Node<type> *currentNode = nullptr;
    Node<type> *nextNode = head;
    while (nextNode != nullptr)
    {
        previousNode = currentNode;
        currentNode = nextNode;
        nextNode = nextNode->next;
        // change pointers of current
        currentNode->next = previousNode;
        currentNode->previous = nextNode;
    }
    head = currentNode;

    // reassign tail
    Node<type> *temp = head;
    for (; temp->next != nullptr; temp = temp->next);
    tail = temp;
}