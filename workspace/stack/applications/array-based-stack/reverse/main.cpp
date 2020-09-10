// WAP to reverse the contents of a stack using another stack.

#include <iostream>
#include "stack.h"


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
        << "7. Reverse" << endl << "8. Exit" << endl;
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
                if (!my_stack.is_empty())
                {
                    my_stack.reverse();
                    cout << "Stack is reversed: ";
                    my_stack.display();
                }
                else
                {
                    cout << "Stack is empty, nothing to reverse!!" << endl;
                }
            break;
            case 8:
                exit(0);
            break;
            default:
                cout << "Invalid Input!! Please Try Again.\n" << endl; 
            break;
        }
    }

    return 0;
}

