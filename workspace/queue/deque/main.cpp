#include <iostream>
#include "deque.h"

using namespace std;

int main()
{
    cout << "Deque Data Structure\n";

    Deque<int> deck;

    while (true)
    {
        cout << "Choose one of the following:\n";
        cout << "1. Insert Front\n"
            << "2. Insert Back\n"
            << "3. Erase Front\n"
            << "4. Erase Back\n"
            << "5. Get Front\n"
            << "6. Get Back\n"
            << "7. Get Size\n"
            << "8. Display\n"
            << "9. Exit\n";

        int choice;
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int element;
                cout << "Enter an element: ";
                cin >> element;
                deck.insert_front(element);
                cout << "Inserted at front";
                cout << "Deque: ";
                deck.display();
            }
            break;
            case 2:
            {
                int element;
                cout << "Enter an element: ";
                cin >> element;
                deck.insert_back(element);
                cout << "Inserted at back";
                cout << "Deque: ";
                deck.display();
            }
            break;
            case 3:
            {
                try
                {
                    deck.erase_front();
                    cout << "Erased Front\n";
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                cout << "Deque: ";
                deck.display();
            }
            break;
            case 4:
            {
                try
                {
                    deck.erase_back();
                    cout << "Erased Back\n";
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                cout << "Deque: ";
                deck.display();
            }
            break;
            case 5:
            {
                try
                {
                    cout << "Front Element: " << deck.front() << "\n";
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
            break;
            case 6:
            {
                try
                {
                    cout << "Back Element: " << deck.back() << "\n";
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }  
            }
            break;
            case 7:
            {
                cout << "Size: " << deck.size() << "\n";
            }
            break;
            case 8:
            {
                if (deck.isempty())
                    cout << "Deque is empty\n";
                else 
                {
                    cout << "Deque: ";
                    deck.display();
                }
            }
            break;
            case 9:
                cout << "Exiting...\n";
                exit(0);
            break;
            default:
                cout << "Invalid Choice\n";
            break;
        }
    }

    return 0;
}

