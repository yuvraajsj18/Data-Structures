/*
    Write a recursive function to compute the sum of n numbers passed as an array.
*/

#include <iostream>
using namespace std;

double sum_arr(double arr[], int size)
{
    if (size == 1)
        return arr[0];

    return arr[size - 1] + sum_arr(arr, size - 1);
}

int main()
{
    double arr[] = {1.0, 2.0, 3.0, 4.0, 5.5};

    cout << sum_arr(arr, 5) << endl;

    return 0;
}