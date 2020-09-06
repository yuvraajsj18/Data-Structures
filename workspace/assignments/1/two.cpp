/*
    Write an equivalent iterative function for the given recursive function:
*/
#include <iostream>
using namespace std;

// recursive function
void f1(int i)
{
    if (i > 0)
    {
        cout << (i * 5) << endl;
        f1(i - 1);
    }
}

void f2(int i)
{
    for (int j = i; j > 0; j--)
        cout << (j * 5) << endl;
}

int main()
{
    f1(5);

    cout << endl;

    f2(5);

    return 0;
}