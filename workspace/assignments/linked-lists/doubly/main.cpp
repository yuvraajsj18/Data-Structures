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
            << "11. Exit" << endl
            << "12. get middle\n"
            << "13. Delete odds\n"
            << "14. operator +\n"
            << "15. Set middle\n"
            << "16. insert at position\n"
            << "17. Swap nodes at k\n";
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
            case 12:
            {
                try
                {
                    cout << "Middle element is: " << dlist.get_middle();
                    cout << endl;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
            break;
            case 13:
            {
                dlist.delete_odd();
                cout << "Deleted odd nodes\n";
                dlist.display();
            }
            break;
            case 14:
            {
                Dlist<int> l2;
                for (int i = 1; i <= 5; i++)
                    l2.add_tail(i);
                
                Dlist<int> sum;
                sum = dlist + l2;
                cout << "Sum of your list and 1,2,3,4,5 is\n";
                sum.display();
            }
            break;
            case 15:
            {
                int element;
                cout << "Enter element to insert in middle: ";
                cin >> element;
                dlist.set_middle(element);
                cout << "Added\n";
                dlist.display();
            }
            break;
            case 16:
            {
                int element, position;
                cout << "Enter an element: ";
                cin >> element;
                cout << "Enter a position: ";
                cin >> position;
                try
                {
                    dlist.insert(element, position);
                    cout << "Added.\n";
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                dlist.display();
            }
            break;
            case 17:
            {
                int k;
                cout << "Enter k to swap nodes: ";
                cin >> k;
                
                dlist.swap_nodes(k);
                cout << "Swapped nodes at k\n";
                dlist.display();
            }
            break;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}

