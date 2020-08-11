/**
 * Write a simple calculator program that adds, subtracts, multiplies and divide two numbers using a  class template.
 */

#include <iostream>
using namespace std;

template <typename type>
class Calculator
{
    public:
        static type add(type num1, type num2);
        static type subtract(type num1, type num2);
        static type multiply(type num1, type num2);
        static type divide(type num1, type num2);
};

int main()
{
    cout << Calculator<int>::add(1, 2) << endl;

    cout << Calculator<float>::subtract(2.0f, 1.5f) << endl;

    cout << Calculator<double>::multiply(100.123, 100.1) << endl;

    cout << Calculator<int>::divide(5, 2) << endl;

    return 0;
}

// Calculator function members

template <typename type>    // explicitly mention template when defining funtion outside class
type Calculator<type>::add(type num1, type num2)
{
    return num1 + num2;
}

template <typename type>
type Calculator<type>::subtract(type num1, type num2)
{
    return num1 - num2;
}

template <typename type>
type Calculator<type>::multiply(type num1, type num2)
{
    return num1 * num2;
}

template <typename type>
type Calculator<type>::divide(type num1, type num2)
{
    return num1 / num2;
}