template <typename type>
Queue<type> :: Queue()
{
    tail = nullptr;
    num_elements = 0;
}

template <typename type>
Queue<type> :: ~Queue()
{
    if (tail != nullptr)
    {
        Node<type> *temp = tail->next;
        while (temp != tail)
        {
            Node<type> *new_temp = temp->next;
            delete temp;
            temp = new_temp;
        }
        delete tail;
    }
}

template <typename type>
bool Queue<type> :: isempty()
{
    return tail == nullptr;
}



template <typename type>
void Queue<type> :: enqueue(type element)
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

    num_elements++;
}

template <typename type>
type Queue<type> :: dequeue()
{
    if (tail == nullptr)
        throw runtime_error("Underflow! queue is empty");
    
    type saved_data = tail->next->data;
    Node<type> *temp_head = tail->next;

    if (tail == tail->next)
        tail = nullptr;
    else
        tail->next = temp_head->next;
    
    delete temp_head;

    num_elements--;
    return saved_data;
}

template <typename type>
void Queue<type> :: display()
{
    if (tail == nullptr)
        return;
    
    Node<type> *temp = tail->next;
    while (temp != tail)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << tail->data << "\n";
}

template <typename type>
int Queue<type> :: size()
{
    return num_elements;
}

template <typename type>
type Queue<type> :: get_front()
{
    if (tail == nullptr)
        throw runtime_error("Queue is empty");

    return tail->next->data;
}

template <typename type>
void Queue<type> :: clear()
{
    if (tail != nullptr)
    {
        Node<type> *temp = tail->next;
        while (temp != tail)
        {
            Node<type> *new_temp = temp->next;
            delete temp;
            temp = new_temp;
        }
        delete tail;
    }
    tail = nullptr;
    num_elements = 0;
}
