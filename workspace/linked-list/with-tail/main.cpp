#include <iostream>
#include <cstdlib>
#include "slist.h"
using namespace std;

template <typename type>
void menu(Slist<type> list);

int main()
{
    cout << "Singly Linked List\n";

    cout << "1. Character list" << endl;
    cout << "2. Integer list" << endl;
    cout << "Choose an option: ";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        Slist<char> list;
        menu<char>(list);
    }
    else if (choice == 2)
    {
        Slist<int> list;
        menu<int>(list);
    }
    else
    {
        cout << "Invalid input" << endl;
        exit(1);
    }
    return 0;
}

template <typename type>
void menu(Slist<type> list)
{
while(true)
    {
        int choice;
        cout << "\n\nChoose an option:\n";
        cout << "1. Add head" << endl
            << "2. Add tail" << endl
            << "3. Delete head" << endl
            << "4. Delete tail" << endl
            << "5. Delete a node" << endl
            << "6. Search" << endl
            << "7. Count Node" << endl
            << "8. Display" << endl
            << "9. Reverse" << endl
            << "10. Is empty" << endl
            << "11. Exit" << endl;
        cout << "Enter a choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                type headElement;
                cout << "Enter an element: ";
                cin >> headElement;
                list.add_head(headElement);
                cout << "Element Added." << endl;
            break;
            case 2:
                type tailElement;
                cout << "Enter an element: ";
                cin >> tailElement;
                list.add_tail(tailElement);
                cout << "Element Added." << endl;
            break;
            case 3:
                if (!list.is_empty())
                {
                    list.delete_head();
                    cout << "Head element deleted." << endl;
                }
                else
                {
                    cout << "List is empty" << endl;
                }
            break;
            case 4:
                if (!list.is_empty())
                {
                    list.delete_tail();
                    cout << "Tail element deleted." << endl;
                }
                else
                {
                    cout << "List is empty" << endl;
                }
            break;
            case 5:
                type element;
                cout << "Enter an element to delete: ";
                cin >> element;
                if (list.is_empty())
                {
                    cout << "List is empty" << endl;
                }
                else if (list.search(element))
                {
                    list.delete_node(element);
                    cout << "Element deleted." << endl;
                }
                else
                {
                    cout << "Element not found in the list" << endl;
                }
            break;
            case 6:
                type searchElement;
                cout << "Enter an element to search: ";
                cin >> searchElement;
                if (list.search(searchElement))
                    cout << "Element found in the list" << endl;
                else 
                    cout << "Element not found in the list" << endl;
            break;
            case 7:
                cout << "Number of nodes: " << list.count_node() << endl;
            break;
            case 8:
                list.display();
            break;
            case 9:
                list.reverse();
                cout << "List is reversed." << endl;
            break;
            case 10:
                if (list.is_empty())
                    cout << "List is empty" << endl;
                else
                    cout << "List is not empty" << endl;
            break;
            case 11:
                exit(0);
            break;
            default:
                cout << "Invalid Input" << endl;
            break;
        }
     }
}