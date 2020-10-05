#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <deque>

using namespace std;

void vector_menu();
void list_menu();
void queue_menu();
void deque_menu();

void clearScreen();
void wait_confirm();

int main()
{
    while (true)
    {
        clearScreen();
        cout << "Containers in STL\n";
        int choice;
        cout << "Choose one of the following:\n";
        cout << "1. Vectors\n"
            << "2. Lists\n"
            << "3. Queues\n"
            << "4. Dequeues\n"
            << "5. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                vector_menu();
            break;
            case 2:
                list_menu();
            break;
            case 3:
                queue_menu();
            break;
            case 4:
                deque_menu();
            break;
            case 5:
                cout << "Exiting...\n";
                exit(0);
            break;
            default:
                cout << "Invalid option\n";
        }
        wait_confirm();
    }

    return 0;
}

void deque_menu()
{
    deque<int> deck;
    deque<int>::iterator Iter;
    
    while (true)
    {
        clearScreen();
        cout << "Queues in STL\n";
        cout << "\n\nChoose one of the following:\n";
        cout << "1. Insert Front\n"
            << "2. Insert Back\n"
            << "3. Erase Front\n"
            << "4. Erase Back\n"
            << "5. Get Front\n"
            << "6. Get Back\n"
            << "7. Get Size\n"
            << "8. Display\n"
            << "9. Go Back\n";

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
                deck.push_front(element);
                cout << "Inserted at front\n";
            }
            break;
            case 2:
            {
                int element;
                cout << "Enter an element: ";
                cin >> element;
                deck.push_back(element);
                cout << "Inserted at back\n";
            }
            break;
            case 3:
            {
                deck.pop_front();
                cout << "Erased Front\n";
            }
            break;
            case 4:
            {
                deck.pop_back();
                cout << "Erased Back\n";
            }
            break;
            case 5:
            {
                cout << "Front Element: " << deck.front() << "\n";
            }
            break;
            case 6:
            {
                cout << "Back Element: " << deck.back() << "\n";
            }
            break;
            case 7:
            {
                cout << "Size: " << deck.size() << "\n";
            }
            break;
            case 8:
            {
                if (deck.empty())
                    cout << "Deque is empty\n";
                else 
                {
                    cout << "Deque: ";
                    for (Iter = deck.begin(); Iter != deck.end(); Iter++)
                        cout << *Iter << " ";
                    cout << "\n";
                }
            }
            break;
            case 9:
                return;
            break;
            default:
                cout << "Invalid Choice\n";
            break;
        }
        wait_confirm();
    }
}

void queue_menu()
{
    queue<int> aqueue;
    
    while (true)
    {
        clearScreen();
        cout << "Queues in STL\n";
        cout << "\n\nChoose one of the following:\n";
        cout << "1. enqueue\n"
            << "2. dequeue\n"
            << "3. get front\n"
            << "4. get back\n"
            << "5. is empty\n"
            << "6. Get size\n"
            << "7. Exit\n";
        int choice;
        cout << "Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                int element;
                cout << "Enter an element: ";
                cin >> element;
                aqueue.push(element);
                cout << "Element enqueued\n";
            }
            break;
            case 2:
            {
                cout << "Front element before pop: " << aqueue.front() << "\n";
                aqueue.pop();
                cout << "Front element after pop: " << aqueue.front() << "\n";
            }
            break;
            case 3:
            {
                int front = aqueue.front();
                cout << "Front Element: " << front << "\n";
            }
            break;
            case 4:
            {
                int front = aqueue.back();
                cout << "Back Element: " << front << "\n";
            }
            break;
            case 5:
                if (aqueue.empty())
                    cout << "Queue is empty\n";
                else 
                    cout << "Queue is not empty\n";
            break;
            case 6:
                cout << "Size: " << aqueue.size() << "\n";
            break;
            case 7:
                cout << "Go back\n";
                return;
            break;
            default:
                cout << "Invalid Option\n";
            break;
        }
        wait_confirm();
    }
}

void list_menu()
{
    list<int> alist;
    list<int>::iterator Iter;
    while (true)
    {
        clearScreen();
        cout << "Lists in STL\n";
        cout << "1. Get size of list\n"
            << "2. Is list empty\n"
            << "3. Get first element\n"
            << "4. Get last element\n"
            << "5. Push front\n"
            << "6. Push Back\n"
            << "7. Pop Front\n"
            << "8. Pop Back\n"
            << "9. Display\n"
            << "10. Go back\n";

        int choice;
        cout << "Enter choice: ";
        cin >> choice;

        cout << "\n";
        int element;
        switch (choice)
        {
            case 1:
                cout << "Size: " << alist.size() << endl;
            break;
            case 2:
                if (alist.empty())
                    cout << "List is empty\n";
                else
                    cout << "List is not empty\n";
            break;
            case 3:
                cout << "First element: " << alist.front() << endl;
            break;
            case 4:
                cout << "Last element: " << alist.back() << endl;
            break;
            case 5:
                cout << "Enter element: ";
                cin >> element;
                alist.push_front(element);
                cout << "Pushed to front\n";
            break;
            case 6:
                cout << "Enter element: ";
                cin >> element;
                alist.push_back(element);
                cout << "Pushed to back\n";
            break;
            case 7:
                alist.pop_front();
                cout << "Popped front\n";
            break;
            case 8:
                alist.pop_back();
                cout << "Popped back\n";
            break;
            case 9:
                for (Iter = alist.begin(); Iter != alist.end(); Iter++)
                    cout << *Iter << " ";
                cout << endl;
            break;
            case 10:
                return;
            break;
            default:
                cout << "Invalid option\n";
            break;
        }
        wait_confirm();
    }
}

void vector_menu()
{
    vector<int> vect;
    vector<int>::iterator Iter;
    while (true)
    {
        clearScreen();
        cout << "Vectors in STL\n";
        cout << "1. Get size of vector\n"
            << "2. Is vector empty?\n"
            << "3. Resize vector\n"
            << "4. Reserve space\n"
            << "5. Get element at i using []\n"
            << "6. Get element at i using at(i)\n"
            << "7. Get first element\n"
            << "8. Get last element\n"
            << "9. Push Back\n"
            << "10. Pop Back\n"
            << "11. Change value at position\n"
            << "12. Display vector\n"
            << "13. Go back\n";
        
        int choice;
        cout << "Enter a choice: ";
        cin >> choice;

        cout << "\n";
        switch(choice)
        {
            case 1:
                cout << "Size: " << vect.size() << endl;
            break;
            case 2:
                if (vect.empty())
                    cout << "Vector is empty\n";
                else 
                    cout << "Vector is not empty\n";
            break;
            case 3:
                int new_size;
                cout << "Enter new size: ";
                cin >> new_size;
                vect.resize(new_size);
                cout << "Vector Resized\n";
            break;
            case 4:
                int space;
                cout << "Enter space to reserve: ";
                cin >> space;
                vect.reserve(space);
                cout << "Space reserved\n";
            break;
            case 5:
                int position1;
                cout << "Enter position: ";
                cin >> position1;
                cout << "Element at given position: " << vect[position1] << endl;
            break;
            case 6:
                int position2;
                cout << "Enter position: ";
                cin >> position2;
                cout << "Element at given position: " << vect.at(position2) << endl;
            break;
            case 7:
                cout << "First element: " << vect.front() << endl;
            break;
            case 8:
                cout << "Last element: " << vect.back() << endl;
            break;
            case 9:
                int element;
                cout << "Enter element: ";
                cin >> element;
                vect.push_back(element);
                cout << "Element pushed back\n";
            break;
            case 10:
                vect.pop_back();
                cout << "Popped back\n";
            break;
            case 11:
                int new_value;
                int position3;
                cout << "Enter position: ";
                cin >> position3;
                cout << "Enter new value: ";
                cin >> new_value;
                vect[position3] = new_value;
                cout << "Value changed\n";
            break;
            case 12:
                for (Iter = vect.begin(); Iter != vect.end(); Iter++)
                    cout << *Iter << " ";
                cout << endl;
            break;
            case 13:
                return;
            break;
            default:
                cout << "Invalid option\n";
        } 
        wait_confirm();
    }
}


void clearScreen()
{
    for (int i = 0; i < 100; i++)
        cout << "\n";
}

void wait_confirm()
{
    cin.ignore();
    string confirm;
    cout << "Press enter to continue: ";
    getline(cin, confirm);
}
