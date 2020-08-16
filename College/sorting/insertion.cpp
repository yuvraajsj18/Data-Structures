/**
 * Data is divided into sorted and unsorted portions. One by one, the unsorted 
 * values are inserted into their appropriate positions in the sorted subarray.
 */

#include <iostream>
using namespace std;

template <typename type>
void insertion_sort(type array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        type to_sort = array[i];

        // find postion for ith element in sorted sub array from right to left
        int j = i - 1; // j is sorted position for ith element
        while(j >= 0 && array[j] > to_sort)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[++j] = to_sort;
    }
}

int main()
{
    const int size = 6;
    int intArr[] = {6, 5, 4, 3, 2, 1};

    insertion_sort<int>(intArr, size);

    for (int i = 0; i < size; i++)
    {
        cout << intArr[i] << " ";
    }
    cout << endl;

    return 0;
}