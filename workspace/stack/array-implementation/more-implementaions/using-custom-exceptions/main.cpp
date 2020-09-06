/**
 * Stack with array implementation
 */

#include <iostream>
#include "stack.h"
using namespace std;

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
        <<"7. Check assignment operator\n" << "8. Check copy constructor\n"
        << "9. Exit" << endl;
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
                catch(const StackException& e)
                {
                    std::cerr << e.what() << '\n';
                }
            break;
            case 2:
                try
                {
                    int popped_element = my_stack.pop();
                    cout << "Top most element popped: " << popped_element << endl;                
                }
                catch(const StackException& e)
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
                catch(const StackException& e)
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
            {
                Stack<int, stack_size> stack2;
                stack2 = my_stack;
                cout << "my_stack assigned to stack2\n";
                cout << "stack2: ";
                stack2.display();
            }
            break;
            case 8:
            {
                Stack<int, stack_size> stack3(my_stack);
                cout << "my_stack copied to stack3\n";
                cout << "stack3: ";
                stack3.display();
            }
            break;
            case 9:
                exit(0);
            break;
            default:
                cout << "Invalid Input!! Please Try Again.\n" << endl; 
            break;
        }
    }

    return 0;
}