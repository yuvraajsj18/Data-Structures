#include <iostream>
#include "clist.h"

using namespace std;

int main()
{
    cout << "Circular Linked List" << endl;

    Clist<int> clist;
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
                clist.add_head(element);
                cout << "Added\n";
                clist.display();
            }
            break;
            case 2:
            {
                int element;
                cout << "Enter an element: ";
                cin >> element;
                clist.add_tail(element);
                cout << "Added\n";
                clist.display();
            }
            break;
            case 3:
            {
                try
                {
                    clist.delete_head();
                    cout << "Deleted head\n";
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                clist.display();
            }
            break;
            case 4:
            {
                try
                {
                    clist.delete_tail();
                    cout << "Deleted tail\n";
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                clist.display();
            }
            break;
            case 5:
            {
                int element;
                cout << "Enter an element to delete: ";
                cin >> element;
                try
                {
                    clist.delete_node(element);
                    cout << "Deleted node with " << element << endl;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                clist.display();
            }
            break;
            case 6:
            {
                int element;
                cout << "Enter an element to search: ";
                cin >> element;
                if (clist.search(element))
                    cout << "Element found in the list\n";
                else 
                    cout << "Element not found in the list\n";
            }
            break;
            case 7:
            {
                cout << "Number of nodes in the list: " << clist.count_node() << endl;
            }
            break;
            case 8:
            {
                if (clist.isempty())
                {
                    cout << "List is empty\n";
                }
                else
                {
                    cout << "List: ";
                    clist.display();
                }
            }
            break;
            case 9:
            {
                if (clist.isempty())
                    cout << "List is empty\n";
                else 
                    cout << "List is not empty\n";
            }
            break;
            case 10:
            {
                clist.reverse();
                cout << "List reversed.\n";
                clist.display();
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

