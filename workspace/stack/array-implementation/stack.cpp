/**
 * Stack with array implementation
 */

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename type, int size>
class Stack
{
    private:
        type* stack; // stack is a dynamically allocated array that will contains all our elements.
        int top;    // index of top element in stack

    public:
        Stack();
        ~Stack();

        bool is_empty();    // Return true if stack is empty, false otherwise.
        void push(type element);    // insert 'element' at the top of stack, if not overflow
        type pop();     // remove element at the top of stack if not underflow
        void display();     // print all elements in stack to console 
        type get_top_element();     // returns the top element
        void clear();       // remove all elements in the stack and reset top.
};

int main()
{
    cout << "Stack implemented as Array";

    const int stack_size = 5;
    Stack<int, stack_size> my_stack;

    int choice;
    while(true)
    {
        cout << "\nChoose an operation:\n";
        cout << "1. Push\n" << "2. Pop\n" << "3. Display\n"
        << "4. Display top\n" << "5. Stack empty?\n" << "6. Clear stack\n" 
        << "7. Exit" << endl;
        cout << "Enter a choice(1-6): ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                int element;
                cout << "Enter element to push: ";
                cin >> element;
                try
                {
                    my_stack.push(element);
                    cout << "Pushed to stack\n";
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            break;
            case 2:
                try
                {
                    int popped_element = my_stack.pop();
                    cout << "Top most element popped: " << popped_element << endl;                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            break;
            case 3:
                my_stack.display();
            break;
            case 4:
                try
                {
                    cout << my_stack.get_top_element() << endl;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            break;
            case 5:
                my_stack.is_empty() ? cout << "Stack is empty right now.\n" : cout << "Stack is not empty right now.\n";
            break;
            case 6:
                my_stack.clear();
                cout << "Stack cleared.\n";
            break;
            case 7:
                exit(0);
            break;
            default:
                cout << "Invalid Input!! Please Try Again.\n" << endl; 
            break;
        }
    }

    return 0;
}

// member functions of Stack

template <typename type, int size>
Stack<type, size> :: Stack()
{
    // create a stack with array of size - 'size'
    stack = new type[size];
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
        throw out_of_range("Stack Underflow!! No more element to pop.");
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
    if (is_empty())
    {
        throw out_of_range("Stack is empty!!");
    }
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
