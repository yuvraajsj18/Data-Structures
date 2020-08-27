#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

int main(int argc, char* argv[])
{
    if (argv[1] && string(argv[1]) == "--help")
    {
        cout << "Dilimeter Matching Program" << endl;
        cout << "To run the program, use 1 of the following method:\n";
        cout << "1. ./dilimeter < filename\n";
        cout << "2. ./dilimeter\n"
             << "then enter your string when prompted.\n"
             << "Press control d(linux)/control z(windows) to mark the end of input.";
        return 0;
    }

    

    return 0;
}