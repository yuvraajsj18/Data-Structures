/**
 * Data is divided into sorted and unsorted portions. One by one, the smallest_index 
 * values remaining in the unsorted portion are selected and swapped over to the 
 * sorted portion of the array.
 */

#include <iostream>
using namespace std;

template <typename type>
void selection_sort(type array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        type smallest_index = i;    // index of smallest element
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[smallest_index])
            {
                smallest_index = j;   // find the smallest element
            }
        }
        if (array[smallest_index] != array[i])
            swap(array[i], array[smallest_index]);  // put that smallest element in sorted array
    }
}

int main()
{
    const int size = 6;
    int intArr[] = {6, 5, 4, 3, 2, 1};

    selection_sort<int>(intArr, size);

    for (int i = 0; i < size; i++)
    {
        cout << intArr[i] << " ";
    }
    cout << endl;

    return 0;
}