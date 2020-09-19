#include <iostream>
#include "dlist.h"

using namespace std;

int main()
{
    cout << "Doubly Linked List" << endl;

    Dlist<int> dlist;
    while (true)
    {
        int choice;
        cout << "Choose an option:\n";
        cout << "1. add head" << endl
            << "2. add tail" << endl
            << "3. delete head" << endl
            << "4. delete tail" << endl
            << "5. delete node" << endl
            << "6. search" << endl
            << "7. count node" << endl
            << "8. display" << endl
            << "9. isempty" << endl
            << "10. reverse" << endl
            << "11. Exit" << endl;
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                int element;
                cout << "Enter an element: ";
                cin >> element;
                dlist.add_head(element);
                cout << "Added\n";
                dlist.display();
            }
            break;
            case 2:
            {
                int element;
                cout << "Enter an element: ";
                cin >> element;
                dlist.add_tail(element);
                cout << "Added\n";
                dlist.display();
            }
            break;
            case 3:
            {
                try
                {
                    dlist.delete_head();
                    cout << "Deleted head\n";
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                dlist.display();
            }
            break;
            case 4:
            {
                try
                {
                    dlist.delete_tail();
                    cout << "Deleted tail\n";
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                dlist.display();
            }
            break;
            case 5:
            {
                int element;
                cout << "Enter an element to delete: ";
                cin >> element;
                try
                {
                    dlist.delete_node(element);
                    cout << "Deleted node with " << element << endl;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                dlist.display();
            }
            break;
            case 6:
            {
                int element;
                cout << "Enter an element to search: ";
                cin >> element;
                if (dlist.search(element))
                    cout << "Element found in the list\n";
                else 
                    cout << "Element not found in the list\n";
            }
            break;
            case 7:
            {
                cout << "Number of nodes in the list: " << dlist.count_node() << endl;
            }
            break;
            case 8:
            {
                if (dlist.isempty())
                {
                    cout << "List is empty\n";
                }
                else
                {
                    cout << "List: ";
                    dlist.display();
                }
            }
            break;
            case 9:
            {
                if (dlist.isempty())
                    cout << "List is empty\n";
                else 
                    cout << "List is not empty\n";
            }
            break;
            case 10:
            {
                dlist.reverse();
                cout << "List reversed.\n";
                dlist.display();
            }
            break;
            case 11:
                exit(0);
            break;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}

