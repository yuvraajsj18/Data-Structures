#include "sequence.h"
#include <iostream>

void clearScreen();

int main()
{

    NodeSequence<int> seq;
    
    while (true)
    {
        clearScreen();

        std::cout << "Node List Class with Iterator\n";
        std::cout << "Choose an option:\n";
        std::cout << "1. Insert Front\n"
                    << "2. Insert Back\n"
                    << "3. Insert at position\n"
                    << "4. Erase Front\n"
                    << "5. Erase Back\n"
                    << "6. Erase at position\n"
                    << "7. Get begin iterator\n"
                    << "8. Get end iterator\n"
                    << "9. Is empty?\n"
                    << "10.Get size\n"
                    << "11. Display\n"
                    << "12. index of\n"
                    << "13. at index\n"
                    << "14. Exit\n";

        int choice;
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int element;
            std::cout << "Enter an element: ";
            std::cin >> element;

            seq.insert_front(element);
            std::cout << "Inserted at front\n";
        }
            break;
        
        case 2:
        {
            int element;
            std::cout << "Enter an element: ";
            std::cin >> element;

            seq.insert_back(element);
            std::cout << "Inserted at back\n";
        }
            break;
        
        case 3:
        {
            int element;
            std::cout << "Enter an element: ";
            std::cin >> element;
            int position;
            std::cout << "Enter a position[1-size]: ";
            std::cin >> position;

            if (position > seq.size())
                std::cout << "Invalid position\n";
            else
            {
                // find iterator position
                NodeList<int>::Iterator iter = seq.begin();
                for (; iter != seq.end() && position != 1; ++iter, position--);
                seq.insert(iter, element);
                std::cout << "Inserted at position\n";
            }
        }
            break;
        
        case 4:
        {
            try
            {
                seq.erase_front();
                std::cout << "Erased front\n";
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
            
            break;
        
        case 5:
        {
            try
            {
                seq.erase_back();
                std::cout << "Erased back\n";
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
            
            break;
        
        case 6:
        {
            int position;
            std::cout << "Enter a position[1-size]: ";
            std::cin >> position;

            if (position > seq.size())
                std::cout << "Invalid position\n";
            else
            {
                // find iterator position
                NodeList<int>::Iterator iter = seq.begin();
                for (; iter != seq.end() && position != 1; ++iter, position--);
                try
                {
                    seq.erase(iter);
                    std::cout << "Erased\n";
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
        }
            
            break;
        
        case 7:
        {
            NodeList<int>::Iterator begin_iter = seq.begin();
            std::cout << "Begin iterator value: " << *begin_iter << "\n";
        }
            break;
        
        case 8:
        {
            NodeList<int>::Iterator end_iter = seq.end();
            std::cout << "End iterator value: " << *end_iter << "\n";
        }
            
            break;
        
        case 9:
        {
            if (seq.empty())
                std::cout << "Node List is empty\n";
            else 
                std::cout << "Node List is not empty\n";
        }
            break;
        
        case 10:
        {
            std::cout << "Size = " << seq.size() << "\n";
        }
            break;
        
        case 11:
        {
            std::cout << "Node List: ";
            for (NodeList<int>::Iterator iter = seq.begin(); iter != seq.end(); ++iter)
                std::cout << *iter << " ";
            std::cout << "\n";
        }
            break;

        case 12:
        {
            std::cout << "Index of all positions:\n";
            for (NodeList<int>::Iterator iter = seq.begin(); iter != seq.end(); ++iter)
                std::cout << *iter << " at index " << seq.index_of(iter) << "\n";
            std::cout << "\n";
        }
            break;

        case 13:
        {
            int index;
            std::cout << "Enter index: ";
            std::cin >> index;
            try
            {
               NodeSequence<int>::Iterator position = seq.at_index(index); 
               std::cout << "Position: " << &position << "\n";
               std::cout << "Value: " << *position << "\n";
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
            break;

        case 14:
        {
            std::cout << "Exiting...\n";
            exit(0);
        }
            break;
        
        default:
            std::cout << "Invalid option\n";
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
