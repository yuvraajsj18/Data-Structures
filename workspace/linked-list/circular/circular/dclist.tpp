#include "dclist.h"

// Node Class

template <typename type>
Node<type>::Node(const type& data, Node<type>* previous, Node<type>* next)
{
    this->type = data;
    this->previous = previous;
    this->next = next;
}


// DCList

template <typename type>
DCList<type>::DCList()
{
    tail = nullptr;
}

template <typename type>
DCList<type>::~DCList()
{
    if (tail != nullptr)
    {
        Node<type>* head = tail->next;
        while (head != tail)
        {
            Node<type> *temp = head->next;
            delete head;
            head = temp;
        }
        delete tail;
    }
}

template <typename type>
void DCList<type>::insert_front(const type& element)
{
    if (tail == nullptr)
    {
        tail = new Node(element);
        tail->previous = tail;
        tail->next = tail;
    }
    else
    {
        tail->next = new Node(element, tail, tail->next);
    }
}

template <typename type>
void DCList<type>::insert_after(const type& after, const type& element)
{
    if (tail == nullptr)
        throw std::runtime_error("Given element not found");

    Node* after_node = tail->next;
    for (; after_node != tail && after_node->data != after; after_node=after_node->next);

    if (after_node->data != after)
        throw std::runtime_error("Given element not found");

    Node<type>* new_node = new Node(element, after_node, after_node->next);
    after_node->next = new_node;
    new_node->next->previous = new_node;
}

template <typename type>
void DCList<type>::insert_back(const type& element)
{
    if (tail == nullptr)
    {
        tail = new Node(element);
        tail->previous = tail;
        tail->next = tail;
    }
    else
    {
        tail->next = new Node(element, tail, tail->next);
        tail = tail->next;
    }
}

template <typename type>
type DCList<type>::remove_back()
{
    if (tail == nullptr)
        throw std::runtime_error("Underflow! List is empty");

    type save_date = tail->data;
    Node<type>* temp_tail = tail;

    if (tail == tail->next)
        tail = nullptr;
    else
        tail = tail->previous;

    delete temp_tail;
    return save_date;
}

template <typename type>
type DCList<type>::remove_front()
{
    if (tail == nullptr)
        throw std::runtime_error("Underflow! List is empty");

    type save_data = tail->next->data;
    Node<type>* temp_head = tail->next;

    if (tail == tail->next)
        tail=nullptr;
    else 
        tail->next = temp_head->next;
    
    delete temp_head;
    return save_data;
}

template <typename type>
type DCList<type>::remove_element(const type& element)
{
    if (tail == nullptr)
        throw std::runtime_error("Underflow! List is empty");

    Node<type>* temp = tail->next;
    for (; temp != tail && temp->data != element; temp=temp->next);

    if (temp->data != element)  // element not found
        throw std::runtime_error("Element is not present in the list");

    temp->previous->next = temp->next;
    temp->next->previous = temp->previous;

    type save_data = temp->data;
    delete temp;

    return save_data;
}

template <typename type>
Node<type>* DCList<type>::search_node(const type& element)
{
    if (tail == nullptr)
        return nullptr;

    Node<type>* temp = tail->next;
    for (; temp != tail && temp->data != element; temp=temp->next);

    if (temp->data != element)
        return nullptr;     // Not found

    return temp;
}

template <typename type>
void DCList<type>::concat(const DCList<type>& with)
{
    if (with.tail == nullptr)
        return;      // Nothing to concat

    Node<type>* temp = with.tail->next;
    while (temp != with.tail)
    {
        insert_back(temp->data);
        temp = temp->data;
    }
    insert_back(with.tail->data);
}

template <typename type>
void DCList<type>::display()
{
    if (tail == nullptr)
        return;

    Node<type>* temp = tail->next;
    while (temp != tail)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << tail->data << "\n";
}

template <typename type>
int DCList<type>::count()
{
    if (tail == nullptr)
        return 0;

    Node<type>* temp = tail->next;
    int count = 1;  // there is one atleast, the tail
    for (; temp != tail; temp=temp->next);

    return count;
}
