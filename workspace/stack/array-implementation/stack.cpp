/**
 * Stack with array implementation
 */

#include <iostream>
#include <stdexcept>

template <typename type, int size>
class Stack
{
    private:
        type* stack; // stack is a dynamic array that will contains all our elements.
        int top;    // index of top element in stack

    public:
        Stack();
        ~Stack();

        bool is_empty();    // Return true if stack is empty, false otherwise.
        void push(type element);    // insert 'element' at the top of stack, if not overflow
        type pop();     // remove element at the top of stack if not underflow
        void display();     // print all elements in stack to console 
        type get_top_element();     // returns the top element
        void clear();       // remove all elements in the stack and reset it.
};

int main()
{


    return 0;
}

// member functions of Stack

template <typename type, int size>
Stack<type, size> :: Stack()
{
    // create a stack with array of size - 'size'
    stack = new T[size];
    top = -1;   // -1 indicates that there is not element in stack at this moment
}

template <typename type, int size>
Stack<type, size> :: ~Stack()
{
    // free the memory occupied by dynamic array of stack
    delete[] stack;
}

// Return true if stack is empty, false otherwise.
template<typename type, int size>
bool Stack<type, size> :: is_empty()
{
    // stack is empty when top is -1
    return top == -1;   
}

// insert 'element' at the top of stack, if not overflow
template<typename type, int size>
void Stack<type, size> :: push(type element)
{
    // checks for overflow
    if (top == size - 1)
    {
        throw out_of_range("Stack Overflow!! No more space to add elements.");
    }

    // insert element on next position in array
    stack[++top] = element; 
}

// Remove element at the top of stack if not underflow
template<typename type, int size>
type Stack<type, size> :: pop()
{
    // check for underflow
    if (is_empty())
    {
        throw out_of_range('Stack Underflow!! No more element to pop.')
    }

    // pop element
    type element_popped = stack[top--];
    return element_popped;
}

// print all elements in stack to console 
template<typename type, int size>
void Stack<type, size> :: display()
{
    // check for empty stack
    if (is_empty())
    {
        cout << "Woops! stack is empty." << endl;
        return;
    }

    // loop over stack and display all elements
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

// Returns the top element
template <typename type, int size>
type Stack<type, size> :: get_top_element()
{
    return stack[top];
}

// Remove all elements in the stack and reset it.
template <typename type, int size>
void Stack<type, size> :: clear()
{
    // free current memory occupied by the stack
    delete[] stack;
    // reset top
    top = -1;
    // assign new memory
    stack = new type[size];
}
