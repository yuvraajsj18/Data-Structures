#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    cout << "Queue with Circular Lists\n";

    Queue<int> queue;

    while (true)
    {
        cout << "\n\nChoose one of the following:\n";
        cout << "1. enqueue\n"
            << "2. dequeue\n"
            << "3. display\n"
            << "4. get front\n"
            << "5. clear\n"
            << "6. is empty\n"
            << "7. Get size\n"
            << "8. Exit\n";
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
                queue.enqueue(element);
                cout << "Element enqueued\n";
                cout << "Queue: ";
                queue.display();
            }
            break;
            case 2:
            {
                try
                {
                    int element = queue.dequeue();
                    cout << element << " dequeued\n";
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                cout << "Queue: ";
                queue.display();
            }
            break;
            case 3:
                if (queue.isempty())
                    cout << "Queue is empty\n";
                else
                {
                    cout << "Queue: ";
                    queue.display();
                }
            break;
            case 4:
                try
                {
                    int front = queue.get_front();
                    cout << "Front Element: " << front << "\n";
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            break;
            case 5:
                queue.clear();
                cout << "Queue cleared\n";
            break;
            case 6:
                if (queue.isempty())
                    cout << "Queue is empty\n";
                else 
                    cout << "Queue is not empty\n";
            break;
            case 7:
                cout << "Size: " << queue.size() << "\n";
            break;
            case 8:
                cout << "Exiting...\n";
                exit(0);
            break;
        }
    }
}
