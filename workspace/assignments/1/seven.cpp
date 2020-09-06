/*
    Write a recursive function for linear search on an array of integers. The function should
    return the index of the element if it is found else it should return -1.
*/

#include <iostream>
using namespace std;

int linear_search(int item, int arr[], int size)
{
    if (size == 0)
        return -1;
    else if (arr[size - 1] == item)
        return size - 1;
    
    return linear_search(item, arr, size - 1);
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    cout << linear_search(5, arr, 10) << endl;
    cout << linear_search(1, arr, 10) << endl;
    cout << linear_search(10, arr, 10) << endl;
    cout << endl;
    cout << linear_search(-10, arr, 10) << endl;
    cout << linear_search(11, arr, 10) << endl;

    return 0;
}