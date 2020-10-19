/*
Write a menu driven program that asks the user the following options
a) Diagonal Matrix
b) Tridiagonal Matrix
c) Upper Triangular Matrix
d) Lower Triangular Matrix
e) Symmetric Matrix
Each matrix class should be included as a separate header file.
The matrix should be stored by mapping them into 1D arrays.
*/

#include <iostream>
#include "./diagonal/diagonalmatrix.h"
#include "./tridiagonal/tridiagonalmatrix.h"
#include "./uppertriangular/utriangular.h"
#include "./lowertriangular/ltriangular.h"
#include "./symmetric/symmetricmatrix.h"

void clearScreen();

int main()
{
    while (true)
    {
        clearScreen();
        std::cout << "Special Matrices\n";

        std::cout << "Choose one of the following:\n";
        std::cout << "1. Diagonal Matrix\n"
                << "2. Tridiagonal Matrix\n"
                << "3. Upper Triangular Matrix\n"
                << "4. Lower Triangular Matrix\n"
                << "5. Symmetric Matrix\n"
                << "6. Exit\n";

        int choice;
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int size;
                std::cout << "Enter dimention: ";
                std::cin >> size;
                DiagonalMatrix<int> dmat(size);
                std::cout << "Enter your diagonal matrix:\n";
                dmat.input();
                std::cout << "Your diagonal matrix:\n";
                dmat.display();
            }
            break;
            case 2:
            {
                int size;
                std::cout << "Enter dimention: ";
                std::cin >> size;
                TridiagonalMatrix<int> tdmat(size);
                std::cout << "Enter your tridiagonal matrix:\n";
                tdmat.input();
                std::cout << "Your tridiagonal matrix:\n";
                tdmat.display();
            }
            break;
            case 3:
            {
                int size;
                std::cout << "Enter dimention: ";
                std::cin >> size;
                UTriangularMatrix<int> utmat(size);
                std::cout << "Enter your upper triangular matrix:\n";
                utmat.input();
                std::cout << "Your upper triangular matrix:\n";
                utmat.display();
            }
            break;
            case 4:
            {
                int size;
                std::cout << "Enter dimention: ";
                std::cin >> size;
                LTriangularMatrix<int> ltmat(size);
                std::cout << "Enter your lower triangular matrix:\n";
                ltmat.input();
                std::cout << "Your lower triangular matrix:\n";
                ltmat.display();
            }
            break;
            case 5:
            {
                int size;
                std::cout << "Enter dimention: ";
                std::cin >> size;
                SymmetricMatrix<int> smat(size);
                std::cout << "Enter your symmetric matrix:\n";
                smat.input();
                std::cout << "Your symmetric matrix:\n";
                smat.display();
            }
            break;
            case 6:
            {
                std::cout << "Exiting...\n";
                exit(0);
            }
            break;
            default:
                std::cout << "Invalid option. Try again...\n";
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
