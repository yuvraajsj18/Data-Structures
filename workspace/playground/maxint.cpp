// Write a recursive function to compute the maximum element of an integer array.

#include <iostream>
using namespace std;

int main()
{


    return 0;
}

int maxInt(int arr[], int start, int end)
{
    if (start - end == 0)
        return (arr[start] > arr[end]) ? arr[start] : arr[end];
    
    int mid = (start + end) / 2;
    return maxInt(arr, 0, mid);
    
}