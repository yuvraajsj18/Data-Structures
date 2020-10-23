#include "dclist.h"
#include <iostream>


void clearScreen();

int main()
{
    DCList<int> dclist;

    while (true)
    {
        clearScreen();

        std::cout << "Doubly Circular Linked List\n";

        std::cout << "Choose an option:\n"
            << "1. Insert Front\n"
            << "2. Insert After\n"
            << "3. Insert Back\n"
            << "4. Remove Back\n"
            << "5. Remove Front\n"
            << "6. Remove element\n"
            << "7. Search Node\n"
            << "8. Concat\n"
            << "9. Display\n"
            << "10. Count\n"
            << "11. Exit\n";

        int choice;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int element;
            std::cout << "Enter element: ";
            std::cin >> element;
            dclist.insert_front(element);
            std::cout << "Inserted.\n";
            dclist.display();
            break;
        }
        case 2:
        { 
            int element;
            std::cout << "Enter element: ";
            std::cin >> element;
            int after;
            std::cout << "Enter after element: ";
            std::cin >> after;
            dclist.insert_after(after, element);
            std::cout << "Inserted.\n";
            dclist.display();

            break;
        }
        case 3:
        {
            int element;
            std::cout << "Enter element: ";
            std::cin >> element;
            dclist.insert_back(element);
            std::cout << "Inserted.\n";
            dclist.display();

            break;
        }
        case 4:
        {
            try
            {
                dclist.remove_back();
                std::cout << "Removed\n";
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            dclist.display();
            
            break;
        }
        case 5:
        { 
            try
            {
                dclist.remove_front();
                std::cout << "Removed\n";
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            dclist.display();

            break;
        }
        case 6:
        {
            int element;
            std::cout << "Enter element to remove: ";
            std::cin >> element;
            try
            {
                dclist.remove_element(element);
                std::cout << "Removed\n";
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            dclist.display();

            break;
        }
        case 7:
        { 
            int element;
            std::cout << "Enter element to search: ";
            std::cin >> element;

            Node<int> *node = dclist.search_node(element);
            if (node == nullptr)
                std::cout << "Not Found\n";
            else
            {
                std::cout << "Element found\n";
                std::cout << "Node address: " << node << "\n";   
            }
            
            break;
        }
        case 8:
        {
            DCList<int> l;
            for (int i = 1; i <= 5; i++)
                l.insert_back(i);

            dclist.concat(l);

            std::cout << "Concatenated your list with {1, 2, 3, 4, 5}\n";

            dclist.display();

            break;
        }
        case 9:
        {
            if (dclist.count() == 0)
                std::cout << "List is empty\n";
            else 
                dclist.display();

            break;
        }
        case 10:
        {
            std::cout << "Size: " << dclist.count() << "\n";

            break;
        }
        case 11:
            std::cout << "Exiting..\n";
            exit(0);
    
            break;
        default:
            std::cout << "Invalid option. Try Again\n";

            break;
        }

        std::cout << "Press enter to continue..";
        std::cin.ignore();
        std::cin.get();
    }

    return 0;
}

void clearScreen()
{
    for (int i = 0; i < 160; i++)
        std::cout << "\n";
}
