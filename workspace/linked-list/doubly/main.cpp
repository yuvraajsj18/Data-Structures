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
            << "11. Remove at position" << endl
            << "12. Insert at position" << endl
            << "13. Search node pointer" << endl
            << "14. Concat a list" << endl
            << "15. Exit" << endl;
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
            {
                int position;
                cout << "Enter position: ";
                cin >> position;
                try
                {
                    dlist.remove(position);
                    cout << "Deleted element at " << position << endl;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                dlist.display();
            }
            break;
            case 12:
            {
                int position, element;
                cout << "Enter Position: ";
                cin >> position;
                cout << "Enter element: ";
                cin >> element;
                try
                {
                    dlist.insert(element, position);
                    cout << "Added." << endl;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                dlist.display();
            }
            break;
            case 13:
            {
                int element;
                cout << "Enter element to get its pointer: ";
                cin >> element;
                Node<int> *ptr = dlist.searchNode(element);
                if (ptr == nullptr)
                    cout << "Element not found" << endl;
                else 
                {
                    cout << "Element found" << endl;
                    cout << "Pointer address: " << ptr << endl;
                }
            }
            break;
            case 14:
            {
                Dlist<int> l2;
                for (int i = 1; i <= 5; i++)
                    l2.add_tail(i);

                dlist.concat(l2);
                cout << "Your list is concatenate with 1,2,3,4,5\n";
                dlist.display();
            }
            break;
            case 15:
                exit(0);
            break;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}

