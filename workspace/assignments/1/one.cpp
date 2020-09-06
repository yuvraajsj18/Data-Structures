/*
    Write a recursive function to compute the maximum element of an integer array
*/

#include <iostream>
using namespace std;

int max_int(int array[], int size)
{
    if (size == 1)
    {
        return array[0];
    }

    return max(array[size - 1], max_int(array, size - 1));
}

int main()
{
    int arr[] = {1, 4, 2, 6, 3, 10};

    cout << max_int(arr, 6) << endl;

    return 0;
}