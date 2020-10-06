#include <iostream>
#include "vector.h"
using namespace std;

int main()
{
    cout << "Vector with extendable array\n";

    Vector<int> vect;

    while (true)
    {
        cout << "\nChoose an option:\n";
        cout << "1. Insert at index\n"
            << "2. Erase at index\n"
            << "3. Get and change with Operator[]\n"
            << "4. Get and change with at()\n"
            << "5. Reserve space\n"
            << "6. Is vector empty?\n"
            << "7. Get size\n"
            << "8. Check assignment operator\n"
            << "9. Check copy constructor\n"
            << "10. Display\n"
            << "11. Exit\n";

        int choice;
        cout << "Choice: ";
        cin >> choice;

        cout << "\n";
        switch(choice)
        {
            case 1:
            {
                int element;
                cout << "Enter element: ";
                cin >> element;
                int index;
                cout << "Enter index: ";
                cin >> index;
                vect.insert(index, element);
                cout << "Inserted.\n";
                vect.display();
            }
            break;
            case 2:
            {
                int index;
                cout << "Enter index: ";
                cin >> index;
                try
                {
                    vect.erase(index);
                    cout << "Erased.\n";
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                vect.display();
            }
            break;
            case 3:
            {
                int index;
                cout << "Enter index: ";
                cin >> index;
                int element;
                cout << "Enter element: ";
                cin >> element;
                vect[index] = element;
                cout << "Changed to, vect[" << index << "] = " << vect[index] << "\n";
            }
            break;
            case 4:
            {
                int index;
                cout << "Enter index: ";
                cin >> index;
                int element;
                cout << "Enter element: ";
                cin >> element;
                try
                {
                    vect.at(index) = element;
                    cout << "Changed to, vect.at(" << index << ") = " << vect[index] << "\n";
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
            break;
            case 5:
            {
                int space;
                cout << "Enter space: ";
                cin >> space;
                vect.reserve(space);
                cout << "Reserved\n";
            }
            break;
            case 6:
            {
                if (vect.empty())
                    cout << "Vector is empty\n";
                else 
                    cout << "Vector is not empty\n";
            }
            break;
            case 7:
            {
                cout << "Size: " << vect.size() << "\n";
            }
            break;
            case 8:
            {
                Vector<int> v2;
                v2.insert(0, 100);
                v2 = vect;
                cout << "Assigned to v2 = ";
                v2.display();
            }
            break;
            case 9:
            {
                Vector<int> v2(vect);
                cout << "Copied to v2 = ";
                v2.display();
            }
            break;
            case 10:
            {
                if (vect.empty())
                    cout << "Vector is empty\n";
                else
                {
                    cout << "Vector: ";
                    vect.display();
                }
            }
            break;
            case 11:
            {
                cout << "Exiting...\n";
                exit(0);
            }
            break;
            default:
                cout << "Invalid Option\nTry Again...";
        }
    }

    return 0;
}