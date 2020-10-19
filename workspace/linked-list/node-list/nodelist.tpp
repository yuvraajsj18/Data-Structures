// NodeList :: Node

template <typename type>
NodeList<type> :: Node :: Node(const type& data, Node* previous, Node* next)
{
    this->data = data;
    this->previous = previous;
    this->next = next;
}


// NodeList :: Iterator

template <typename type>
NodeList<type> :: Iterator :: Iterator(Node* node)
{
    this->node = node;
}

template <typename type>
type& NodeList<type> :: Iterator :: operator*()
{
    return node->data;
}

template <typename type>
bool NodeList<type> :: Iterator :: operator==(const Iterator& that) const
{
    return this->node == that->node;
}

template <typename type>
bool NodeList<type> :: Iterator :: operator!=(const Iterator& that) const
{
    return this->node != that->node;
}

template <typename type>
NodeList<type> :: Iterator& NodeList<type> :: Iterator :: operator++()
{
    node = node->next;
    return *this;
}

template <typename type>
NodeList<type> :: Iterator& NodeList<type> :: Iterator :: operator--()
{
    node = node->previous;
    return *this;
}


// NodeList
template <typename type>
NodeList<type> :: NodeList()
{
    header = new Node(type());
    trailer = new Node(type());
    header->next = trailer;
    trailer->previous = header;
    num_elements = 0;
}

template <typename type>
NodeList<type> :: ~NodeList()
{
    while (header != nullptr)
    {
        Node* temp = header->next;
        delete head;
        head = temp;
    }
}

template <typename type>
NodeList<type> :: NodeList(const NodeList<type>& that)
{
    header = new Node(type());
    trailer = new Node(type());
    header->next = trailer;
    trailer->previous = header;
    num_elements = 0;

    Node* temp = that->header->next;
    while (temp != this->trailer)
    {
        insert_back(temp->data);
        temp = temp->next;
    }
}

template <typename type>
NodeList<type>& NodeList<type> :: operator=(const NodeList<type>& that)
{
    while (header != nullptr)
    {
        Node* temp = header->next;
        delete head;
        head = temp;
    }

    header = new Node(type());
    trailer = new Node(type());
    header->next = trailer;
    trailer->previous = header;
    num_elements = 0;

    Node* temp = that->header->next;
    while (temp != this->trailer)
    {
        insert_back(temp->data);
        temp = temp->next;
    }
}

template <typename type>
inline int NodeList<type> :: size() const 
{
    return num_elements;
}

template <typename type>
inline bool NodeList<type> :: empty() const
{
    return num_elements == 0;
}

template <typename type>
inline NodeList<type>::Iterator NodeList<type> :: begin() const
{
    return Iterator(header->next);
}

template <typename type>
inline NodeList<type>::Iterator NodeList<type>::end() const 
{
    return Iterator(trailer);
} 

template <typename type>
void NodeList<type>::insert_front(const type& element)
{
    insert(begin(), element);
}

template <typename type>
void NodeList<type>::insert_back(const type& element)
{
    insert(end(), element);
}

template <typename type>
void NodeList<type>::insert(const Iterator& position, const type& element)
{
    Node* newNode = new Node(element, position->node->previous, position->node);
    position->previous->next = newNode;
    position->previous = newNode;

    num_elements++;
}

template <typename type>
type NodeList<type>::eraseFront()
{
    return erase(begin());
}

template <typename type>
type NodeList<type>::eraseBack()
{
    return erase(--end());
}

template <typename type>
type NodeList<type>::erase(const Iterator& position)
{
    if (header->next == trailer)
        throw runtime_error("Underflow! List is empty.");

    Node to_delete = position->node;
    type saved_data = to_delete->data;

    to_delete->previous->next = to_delete->next;
    to_delete->next->previous = to_delete->previous;

    delete to_delete;
    num_elements--;
    return saved_data;
}


