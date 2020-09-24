#include <iostream>
#include "olist.h"
using namespace std;

int main()
{
    Olist<int> olist;
    Olist<int> olist2;
    cout << "Ordered Linked List\n";

    while (true)
    {
        cout << "\nChoose an option:\n";
        cout << "1. Insert in list1\n"
            << "2. Delete in list1\n"
            << "3. Display in list1\n"
            << "4. Search in list1\n"
            << "5. Merge list1 list2\n"
            << "6. isempty list1\n"
            << "7. Insert in list2\n"
            << "8. Delete in list2\n"
            << "9. Exit\n";

        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
            case 1:
            {
                int element;
                cout << "Enter an element to insert: ";
                cin >> element;
                olist.insert(element);
                cout << "List: ";
                olist.display();
            }
            break;
            case 2:
            {
                if (!olist.isempty())
                {
                    int element;
                    cout << "Enter an element to delete: ";
                    cin >> element;
                    try
                    {
                        olist.delete_node(element);
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                    cout << "List: ";
                    olist.display();
                }
                else 
                    cout << "Underflow! list is empty\n";
            }
            break;
            case 3:
            {
                cout << "List: ";
                olist.display();
            }
            break;
            case 4:
            {
                int element;
                cout << "Enter an element to search: ";
                cin >> element;
                if (olist.search(element))
                    cout << "Element found\n";
                else 
                    cout << "Element not found\n";
            }
            break;
            case 5:
            {
                olist.merge(olist, olist2);
                cout << "Merged list1 and list2\n";
                olist.display();
            }
            break;
            case 6:
                if (olist.isempty())
                    cout << "Ordered list is empty\n";
                else 
                    cout << "Order list is not empty\n";
            break;
            case 7:
            {
                int element;
                cout << "Enter an element to insert: ";
                cin >> element;
                olist2.insert(element);
                cout << "List: ";
                olist2.display();
            }
            break;
            case 8:
            {
                if (!olist2.isempty())
                {
                    int element;
                    cout << "Enter an element to delete: ";
                    cin >> element;
                    try
                    {
                        olist2.delete_node(element);
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                    cout << "List: ";
                    olist2.display();
                }
                else 
                    cout << "Underflow! list is empty\n";
            }
            break;
            case 9:
                exit(0);
            break;
            default:
                cout << "Invalid Choice\n";
        }
    }

    return 0;
}
