#include "bst.h"
#include <iostream>

void clearScreen();

int main()
{
    BST<int> bst;

    while (true)
    {
        clearScreen();
        std::cout << "Binary Search Tree\n";

        std::cout << "1. insert (part a of question)\n"
                    << "2. delete by copy\n"
                    << "3. delete by merge\n"
                    << "4. search\n"
                    << "5. inorder display (part b of question)\n"
                    << "6. sum of non leaf nodes (part c of question)\n"
                    << "7. display leaf nodes inorder (part d of question)\n"
                    << "8. empty?\n"
                    << "9. clear\n"
                    << "10. Exit\n";

        int choice;
        std::cout << "Choice: ";
        std::cin >> choice;
        
        switch (choice)
        {
            case 1:     // Part a of question
            {
                int element;
                std::cout << "Enter an element: ";
                std::cin >> element;
                bst.insert(element);
                std::cout << "Inserted\n";
            }
                break;
            case 2:
            {
                int element;
                std::cout << "Enter an element to delete: ";
                std::cin >> element;
                bst.find_del_copy(element);
                std::cout << "Deleted\n";
            }
                break;
            case 3:
            {
                int element;
                std::cout << "Enter an element to delete: ";
                std::cin >> element;
                bst.find_del_merge(element);
                std::cout << "Deleted\n";
            }
                break;
            case 4:
            {
                int element;
                std::cout << "Enter element to search: ";
                std::cin >> element;
                if (bst.search(element) != nullptr)
                    std::cout << "Element found in the tree\n";
                else 
                    std::cout << "Element not found in the tree\n";
            }
                break;
            case 5:     // part b of question
            {
                if (bst.empty())
                    std::cout << "Tree is empty\n";
                else 
                {
                    std::cout << "BST:\n";
                    bst.inorder();
                }
            }
                break;
            case 6:     // part c of question
            {
                std::cout << "Sum of values of all non-leaf nodes: " << bst.sum_nonleaf() << "\n";
            }
                break;
            case 7:
            {
                if (bst.empty())
                    std::cout << "Tree is empty\n";
                else 
                {
                    std::cout << "All leaf nodes of tree inorder:\n";
                    bst.leaf_inorder();
                }   
            }  
                break;
            case 8:
            {
                if (bst.empty())
                    std::cout << "Tree is empty\n";
                else 
                    std::cout << "Tree is not empty\n";
            }
                break;
            case 9:
            {
                bst.clear();
                std::cout << "Tree cleared\n";
            }
                break;
            case 10:
            {
                std::cout << "Exiting...\n";
                exit(0);
            }
                break;
            default:
                std::cout << "Invalid option\n";
                break;
        }

        std::cout << "\nPress enter to continue..";
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
