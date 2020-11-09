#include "bst.h"

 // Binary Search Node Class

template <typename type>
BSTNode<type>::BSTNode()
{
    left = right = nullptr;
}

template <typename type>
BSTNode<type>::BSTNode(const type& key, BSTNode<type>* left, BSTNode<type>* right)
{
    this->key = key;
    this->left = left;
    this->right = right;
}


// Binary Search Tree Class

template <typename type>
BST<type>::BST()
{
    this->root = nullptr;   
}

template <typename type>
BST<type>::~BST()
{
    this->clear();
}


template <typename type>
inline void BST<type>::clear()         // Public clear()
{
    this->clear(this->root);    
    this->root = nullptr;
}

template <typename type>
void BST<type>::clear(BSTNode<type>* node)      // Private clear()
{
    if (node == nullptr)
        return;

    this->clear(node->left);
    this->clear(node->right);

    delete node;
}

template <typename type>
inline bool BST<type>::empty() const
{
    return this->root == nullptr;
}


template <typename type>
void BST<type>::insert(const type& key)
{
    if (this->root == nullptr)
        this->root = new BSTNode<type>(key);
    else
    {
        BSTNode<type>* temp_node = this->root;  // to traverse the tree
        BSTNode<type>* prev_node = nullptr; // parent of temp_node

        while (temp_node != nullptr)    // find right position
        {
            prev_node = temp_node;

            if (temp_node->key < key)
                temp_node = temp_node->right;
            else // if (temp_node->key >= key)
                temp_node = temp_node->left;
        }        

        if (prev_node->key < key)
            prev_node->right = new BSTNode<type>(key);
        else 
            prev_node->left = new BSTNode<type>(key);
    }
}


template <typename type>
BSTNode<type>* BST<type>::search(const type& key) const
{
    return this->search(this->root, key);
}

template <typename type>
BSTNode<type>* BST<type>::search(BSTNode<type>* node, const type& key) const
{
    while (node != nullptr)
    { 
        if (node->key == key)
            return node;
        if (node->key < key)
            node = node->right;
        else 
            node = node->left;
    }

    return nullptr;
}

template <typename type>
void BST<type>::change_key(const type& key, const type& new_key)
{
    if (this->search(key) != nullptr)
    {
        this->find_del_copy(key);
        this->insert(new_key);
    }
    else
    {
        std::cout << "key does not exists\n";   
    }
}


// find the parent to node ptr with key and send it to del_copy function to delete
template <typename type>
void BST<type>::find_del_merge(const type& key)     
{
    BSTNode<type>* temp_node = this->root;
    BSTNode<type>* prev_node = nullptr;

    // find the ptr from parent to the node with key = key
    while (temp_node != nullptr && temp_node->key != key)
    {
        prev_node = temp_node;
        if (temp_node->key < key)
            temp_node = temp_node->right;
        else 
            temp_node = temp_node->left;
    }

    if (temp_node != nullptr && temp_node->key == key)
    {
        if (temp_node == this->root)
            del_merge(root);
        else if (temp_node == prev_node->left)
            del_merge(prev_node->left);
        else
            del_merge(prev_node->right);
    }
    else if (this->root != nullptr)
        std::cout << "Key not found in the binary search tree\n"; // should have thrown an error
    else
        std::cout << "Binary Search Tree is empty\n";   // should have thrown an error
}

template <typename type>
void BST<type>::del_merge(BSTNode<type>*& node) // node is parent -> child ptr 
{
    if (node != nullptr)
    {
        BSTNode<type>* to_delete = node;

        if (node->left == nullptr)
            node = node->right;
        else if (node->right == nullptr)
            node = node->left;
        else    // both left and right child exists
        {   
            BSTNode<type>* temp_node = node->left;

            while (temp_node->right != nullptr)
                temp_node = temp_node->right;   // get the right most child of left child of to_delete node
            
            temp_node->right = node->right;
            node = node->left;  
        }

        delete to_delete;
    }
}


template <typename type>
void BST<type>::find_del_copy(const type& key)
{
    BSTNode<type>* temp_node = this->root;
    BSTNode<type>* prev_node = nullptr;

    while (temp_node != nullptr && temp_node->key != key)
    {
        prev_node = temp_node;
        if (temp_node->key < key)
            temp_node = temp_node->right;
        else 
            temp_node = temp_node->left;
    }

    if (temp_node != nullptr && temp_node->key == key)
    {
        if (temp_node == this->root)
            del_copy(root);
        else if (temp_node == prev_node->right)
            del_copy(prev_node->right);
        else 
            del_copy(prev_node->left);
    }
    else if (this->root != nullptr)
        std::cout << "Key not found in the binary search tree\n"; // should have thrown an error
    else
        std::cout << "Binary search tree is empty\n";   // should have thrown an error
}

template <typename type>
void BST<type>::del_copy(BSTNode<type>*& node)
{
    if (node != nullptr)
    {
        if (node->left == nullptr)
            node = node->right;
        else if (node->right == nullptr)
            node = node->left;
        else
        {
            BSTNode<type>*prev_node = node;
            BSTNode<type>* temp_node = node->left;

            while (temp_node->right != nullptr)
            {
                prev_node = temp_node;
                temp_node = temp_node->right;
            }

            node->key = temp_node->key; // copy the elements

            if (prev_node == node)      // handle the left sub tree of temp_node
                prev_node->left = temp_node->left;
            else 
                prev_node->right = temp_node->left;

            delete temp_node;
        }
    }
}


template <typename type>
void BST<type>::breadth_first()
{
    if (this->empty())
        return;

    std::queue<BSTNode<type>*> nodes_to_visit;
    BSTNode<type>* temp_node = this->root;
    
    nodes_to_visit.push(temp_node);

    while (!nodes_to_visit.empty())
    {
        temp_node = nodes_to_visit.front();
        nodes_to_visit.pop();

        visit(temp_node);

        if (temp_node->left != nullptr)
            nodes_to_visit.push(temp_node->left);
        if (temp_node->right != nullptr)
            nodes_to_visit.push(temp_node->right);
    }
}


template <typename type>
inline void BST<type>::visit(BSTNode<type>* node) const
{
    std::cout << node->key << " ";
}


template <typename type>
void BST<type>::preorder()
{
    if (this->root == nullptr)
        return;
    
    std::stack<BSTNode<type>*> travStack;
    BSTNode<type>* temp_node = this->root;

    travStack.push(temp_node);
    while (!travStack.empty())
    {
        temp_node = travStack.top();
        travStack.pop();
        this->visit(temp_node);

        if (temp_node->right != nullptr)
            travStack.push(temp_node->right);
        if (temp_node->right != nullptr)
            travStack.push(temp_node->left);
    }
}

template <typename type>
void BST<type>::inorder()
{
    if (this->root == nullptr)
        return;

    std::stack<BSTNode<type>*> travStack;
    BSTNode<type>* temp_node = this->root;

    while (temp_node != nullptr)
    {
        while (temp_node != nullptr)
        {
            if (temp_node -> right != nullptr)
                travStack.push(temp_node->right);
            travStack.push(temp_node);
            temp_node = temp_node->left;
        }

        temp_node = travStack.top();
        travStack.pop();

        while (!travStack.empty() && temp_node->right == nullptr)
        {
            visit(temp_node);
            temp_node = travStack.top();
            travStack.pop();
        }

        visit(temp_node);

        if (!travStack.empty())
        {
            temp_node = travStack.top();
            travStack.pop();
        }
        else 
            temp_node == nullptr;
    }
}

template <typename type>
void BST<type>::postorder() 
{
    // TODO
}

