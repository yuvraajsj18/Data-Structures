/**
 * Adjacent values are swapped until the array is completely sorted. This 
 * algorithm gets its name from the way values eventually "bubble" up to their 
 * proper position in the sorted array.
 */

#include <iostream>
#include <string>
using namespace std;

template <typename type>
void bubbleSort(type array[], int array_length)
{
    bool swapped;
    do
    {
        swapped = false;
        for (int i = 0; i < array_length - 1; i++)
        {
            if (array[i] > array[i + 1])    // ascending order
            {
                swap(array[i], array[i + 1]); // swap adjancent value if not in sorted order
                swapped = true;
            }
        }
        // after first pass the biggest element is at last postion and is sorted
        array_length--;
    } while (swapped);  // repeat this until there is no swapping
    
}

template <typename type>
void printArray(type array[], int array_length)
{
    for (int i = 0; i < array_length; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    const int size = 6;
    int intArr[size] = {6, 5, 4, 3, 2, 1};

    for (int i = size; i > 0; i--)
    {
        intArr[i] = i;
    }

    cout << "before sorting: ";
    printArray(intArr, size);

    // sort intArr
    bubbleSort<int>(intArr, size);

    cout << "after sorting: ";
    printArray(intArr, size);

    char charArr[size] = {'z','g','b', 'c', 'a'};
    bubbleSort<char>(charArr, size);
    printArray<char>(charArr, size);

    return 0;
}