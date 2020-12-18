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
            << "11. Insert an element x after element y" << endl
            << "12. Remove an element at position" << endl
            << "13. Concatenate" << endl
            << "14. Search Node" << endl
            << "15. count key\n"
            << "16. Exit" << endl;
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
            {
                int x, y;
                cout << "Enter x: ";
                cin >> x;
                cout << "Enter y: ";
                cin >> y;
                try
                {
                    clist.insert(x, y);
                    cout << "Inserted." << endl;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                clist.display();
            }
            break;
            case 12:
            {
                int position;
                cout << "Enter position: ";
                cin >> position;
                try
                {
                    clist.remove(position);
                    cout << "Removed" << endl;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                clist.display();
            }
            break;
            case 13:
            {
                Clist<int> c1;
                for (int i = 1; i <= 5; i++)
                    c1.add_tail(i);

                cout << "Concatenating your list with 1,2,3,4,5\n";
                clist.concat(c1);
                clist.display();
            }
            break;
            case 14:
            {
                cout << "Enter an element to get its Node: ";
                int element;
                cin >> element;
                Node<int>* node = clist.searchNode(element);
                if (node != nullptr)
                    cout << "Node Found at " << node << endl;
                else
                    cout << "Node not found\n";
            }
            break;
            case 15:
            {
                int key;
                cout << "Enter key to count occurance: ";
                cin >> key;

                cout << "occurs: " << clist.count_key(key) << "\n";
            } 
            break;
            case 16:
                exit(0);
            break;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}

