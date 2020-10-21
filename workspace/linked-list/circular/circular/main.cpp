#include "dclist.h"
#include <iostream>

int main()
{
    while (true)
    {
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
            
            break;
        
        case 2:

            break;
        
        case 3:
            
            break;
        
        case 4:
            
            break;
        
        case 5:
            
            break;
        
        case 6:
            
            break;
        
        case 7:
            
            break;
        
        case 8:
            
            break;
        
        case 9:
            
            break;
        
        case 10:
            
            break;
        
        case 11:
            std::cout << "Exiting..\n";
            exit(0);
    
            break;
        default:
            std::cout << "Invalid option. Try Again\n";

            break;
        }

        std::cout << "Press enter to continue..";
        std::cin.get();
    }

    return 0;
}

void clearScreen()
{
    for (int i = 0; i < 160; i++)
        std::cout << "\n";
}
