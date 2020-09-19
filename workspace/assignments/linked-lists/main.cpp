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
            << "6. Search Element" << endl
            << "7. Count Node" << endl
            << "8. Display" << endl
            << "9. Reverse" << endl
            << "10. Is empty" << endl
            << "11. concatenate" << endl
            << "12. Assignment" << endl
            << "13. Insert at position" << endl
            << "14. Remove at position" << endl
            << "15. Search for a node" << endl
            << "16. Exit" << endl;
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
            {
                Slist<type> to_concat;
                to_concat.add_tail(1); 
                to_concat.add_tail(2); 
                to_concat.add_tail(3);
                cout << "Concatenating your list with [1, 2, 3] into a new list using + and = operator" << endl;
                Slist<type> newList = list + to_concat;
                cout << "newList: ";
                newList.display(); 
            }
            break;
            case 12:
            {
                Slist<type> newList;
                newList = list;
                cout << "new list after assignment is: ";
                newList.display();
            }
            break;
            case 13:
            {
                type element;
                cout << "Enter an element: ";
                cin >> element;
                int position;
                cout << "Enter a position: ";
                cin >> position;
                list.insert(element, position);
                cout << "Inserted" << endl;
                list.display();
            }
            break;
            case 14:
            {
                int position;
                cout << "Enter a position: ";
                cin >> position;
                try
                {
                    list.remove(position);
                    cout << "Removed" << endl;
                    list.display();
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
            break;
            case 15:
            {
                type element;
                cout << "Enter an element: ";
                cin >> element;
                try
                {
                    Node<type> *node = list.searchNode(element);
                    cout << "Node Found" << endl;
                    cout << "Node address: " << node << endl;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
            break;
            case 16:
                exit(0);
            break;
            default:
                cout << "Invalid Input" << endl;
            break;
        }
     }
}