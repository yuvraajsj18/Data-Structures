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

template <typename type>
type Dlist<type> :: get_middle()
{
    if (head == nullptr)
        throw runtime_error("List is empty");
    
    Node<type> *slow_ptr = head;
    Node<type> *fast_ptr = head;

    while (fast_ptr != nullptr && fast_ptr -> next != nullptr)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    return slow_ptr->data;
}


template <typename type>
void Dlist<type> :: delete_odd()
{
    if (head == nullptr)
        return;

    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
        return;
    }

    Node<type> *temp = head;
    Node<type> *pred = nullptr;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        if (count % 2 != 0)
        {
            if (temp == head)
            {
                head = head->next;
                head -> previous = nullptr;
            }
            else
            {
                if (temp == tail)
                {
                    tail = temp->previous;
                    tail->next = nullptr;
                }
                else
                {
                    pred->next = temp->next;
                    temp->next->previous = temp->previous;
                }
            }
            Node<type> *temp1 = temp->next;
            delete temp;
            temp = temp1;
        }
        else
        {
            pred = temp;
            temp = pred->next;
        }
    }
}

template <typename type>
Dlist<type> Dlist<type> :: operator+(const Dlist<type> &list)
{
    Dlist<type> newList;
    Node<type> *temp = head;
    while (temp != nullptr)
    {
        newList.add_tail(temp->data);
        temp = temp->next;
    }
    temp = list.head;
    while (temp != nullptr)
    {
        newList.add_tail(temp->data);
        temp = temp->next;
    }

    return newList;
}

template <typename type>
Dlist<type>& Dlist <type> :: operator=(const Dlist<type> &list)
{
    while (head != nullptr)
    {
        Node<type> *temp = head;
        head = head->next;
        delete temp;
    }

    Node<type> *temp = list.head;
    while (temp != nullptr)
    {
        add_tail(temp->data);
        temp = temp->next;
    }

    return *this;
}

template <typename type>
void Dlist<type> :: set_middle(type element)
{
    if (head == nullptr)
    {
        head = tail = new Node<type>(element);
    }
    else if (head == tail)
    {
        tail->next = new Node<type>(element);
        tail = tail->next;
    }
    else
    {
        Node<type> *slow_ptr = head;
        Node<type> *fast_ptr = head -> next;
        while (fast_ptr != nullptr && fast_ptr->next != nullptr)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }

        Node<type> *newNode = new Node<type>(element, slow_ptr, slow_ptr->next);
        slow_ptr->next->previous = newNode;
        slow_ptr->next = newNode;
    }
}

template <typename type>
void Dlist<type> :: insert(type element, int position)
{
    if (head == nullptr)
    {
        if (position == 0)
            head = tail = new Node<type>(element);
        else
            throw runtime_error("Invalid position");
    }
    else if (position == 0)
    {
        head = new Node<type>(element, nullptr, head);
        head->next->previous = head;
    }
    else
    {
        int count = 0;
        Node<type> *temp = head;
        for (; temp != nullptr && count != position; count++, temp=temp->next);
        if (temp == nullptr && count == position)
        {
            tail->next = new Node<type>(element, tail, nullptr);
            tail = tail->next;
        }
        else if (temp != nullptr)
        {
            Node<type> *newNode = new Node<type>(element, temp->previous, temp);
            temp->previous->next = newNode;
            temp->previous = newNode;
        }
        else
            throw runtime_error("Invalid Position");
    }
}


template <typename type>
void Dlist<type> :: swap_nodes(int k)
{
    if (head == nullptr || head == tail)
        return;

    int node_count = count_node();

    if (k == 1 || k == node_count)  // swap head and tail
    {
        Node<type> *head_next = head->next; // save

        head->next = tail->next;
        head->previous = tail->previous;
        tail->previous->next = head;

        tail->next = head_next;
        tail->previous = nullptr;
        head_next->previous = tail;

        Node<type> *temp = head;
        head = tail;
        tail = temp;
    }
    else
    {
        int count = 1;
        Node<type> *temp1 = head;
        Node<type> *temp2 = tail;
        while (count != k && temp1 != nullptr && temp2 != nullptr)
        {
            temp1 = temp1->next;
            temp2 = temp2->previous;
            count++;
        }
        if (temp1 == nullptr || temp2 == nullptr)
            return; // k outside range
        
        // swap pointers
        
        Node<type> *temp1prev = temp1->previous; // save
        Node<type> *temp1next = temp1->next; // save
        // change pointers of temp1
        temp1->next = temp2->next;
        temp1->previous = temp2->previous;
        temp2->previous->next = temp1;
        temp2->next->previous = temp1;
        // change pointers of temp2
        temp2->next = temp1next;
        temp2->previous = temp1prev;
        temp1next->previous = temp2;
        temp1prev->next = temp2;
    }
}


