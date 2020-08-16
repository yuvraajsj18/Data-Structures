#include <iostream>
using namespace std;

// generic function
template <typename type>
type sum(type num1, type num2)
{
    return num1 + num2;
}

// explicit instantiation of generic function
template int sum<int>(int, int);

int main()
{
    cout << sum<double>(1.5, 2.5) << endl; // implicit instantiation

    cout << sum(1, 2) << endl;

    return 0;
}