/*
    Given the following code. Write its recursive function.
*/

#include <iostream>
using namespace std;

void f(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            cout << (i * i * i) << " ";
    }
}

void foo(int n, int i = 1)
{
    if (i > n)
        return;
    else if(i % 2 == 0)
        cout << (i * i * i) << " ";
    
    return foo(n, ++i);
}

int main()
{
    f(20);

    cout << endl;

    foo(20);

    return 0;
}