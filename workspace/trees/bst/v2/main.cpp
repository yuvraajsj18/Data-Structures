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

        std::cout << "1. insert\n"
                    << "2. delete by copy\n"
                    << "3. delete by merge\n"
                    << "4. search\n"
                    << "5. breadth first display(level by level)\n"
                    << "6. preorder(iterative) display\n"
                    << "7. inorder(iterative) display\n"
                    << "8. postorder(iterative) display\n"
                    << "9. empty?\n"
                    << "10. clear\n"
                    << "11. Change key\n"
                    << "12. Exit\n";

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
                bst.insert(element);
                std::cout << "Inserted\n";
                bst.breadth_first();
            }
                break;
            case 2:
            {
                int element;
                std::cout << "Enter an element to delete: ";
                std::cin >> element;
                bst.find_del_copy(element);
                std::cout << "Deleted\n";
                bst.breadth_first();
            }
                break;
            case 3:
            {
                int element;
                std::cout << "Enter an element to delete: ";
                std::cin >> element;
                bst.find_del_merge(element);
                std::cout << "Deleted\n";
                bst.breadth_first();
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
            case 5:
            {
                if (bst.empty())
                    std::cout << "Tree is empty\n";
                else 
                {
                    std::cout << "BST:\n";
                    bst.breadth_first();
                }
            }
                break;
            case 6:
            {
                if (bst.empty())
                    std::cout << "Tree is empty\n";
                else 
                {
                    std::cout << "BST:\n";
                    bst.preorder();
                }
            }
                break;
            case 7:
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
            case 8:
            {
                if (bst.empty())
                    std::cout << "Tree is empty\n";
                else 
                {
                    std::cout << "BST:\n";
                    bst.postorder();
                }
            }
                break;
            case 9:
            {
                if (bst.empty())
                    std::cout << "Tree is empty\n";
                else 
                    std::cout << "Tree is not empty\n";
            }
                break;
            case 10:
            {
                bst.clear();
                std::cout << "Tree cleared\n";
            }
                break;
            case 11:
            {
                int old_element;
                int new_element;
                std::cout << "Enter old element to replace: ";
                std::cin >> old_element;
                std::cout << "Enter new element: ";
                std::cin >> new_element;
                bst.change_key(old_element, new_element);
                std::cout << "Changed\n";
            }
                break;
            case 12:
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
