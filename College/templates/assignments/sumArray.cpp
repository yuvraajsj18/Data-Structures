/**
 * Write a function template that takes a single type parameter (T) and accepts four function arguments: an array of T, a start index, a stop index (inclusive), and an 
 * optional initial value. The function returns the sum of all the array elements in the specified range and the initial value. 
 * Use the default constructor of T for the default initial value. 
 * Repeat the exercise but use explicit instantiation to manually create specializations for int data type.
 */

#include <iostream>
using namespace std;

template <typename type>
type sumArray(const type arr[], int start, int stop, type initial_value=type())
{
    type sum = initial_value;

    for (int i = start; i <= stop; i++)     // loop on array from start to stop
    {
        sum = sum + arr[i];
    }

    return sum;
}

// explicit instantiation for int
template int sumArray<int>(const int arr[], int start, int stop, int initial_value = 0);

// a custom class to test our function with non promitive datatypes
class CustomDataType
{
    int value;
    public:
    CustomDataType(int value = 10000)  // intital value will be this when doing sum without providing any value
    {
        this -> value = value; 
    }

    int operator+(const CustomDataType &obj)
    {
        return this -> value + obj.value;
    }

    int operator=(const CustomDataType &obj)
    {
        return this -> value = obj.value;
    }

    friend ostream &operator<<( ostream &output, const CustomDataType &obj ) 
    { 
         output << obj.value;
         return output;    
    }
};

int main()
{
    int intArr[] = {1, 2, 3, 4, 5};
    cout << "int array sum: " << sumArray<int>(intArr, 0, 4, 100) << endl;

    float floatArr[] = {1.1f, 2.2f, 3.3f};
    cout << "float array sum: " << sumArray<float>(floatArr, 1, 2) << endl;    // with default initial

    double doubleArr[] = {100.1, 200.2, 300.3, 400.4, 500.5};
    cout << "double array sum: " << sumArray(doubleArr, 2, 4, -1000.1) << endl;

    CustomDataType customArr[] = {CustomDataType(1), CustomDataType(2), CustomDataType(3)};
    cout << "Custom Array sum: " << sumArray<CustomDataType>(customArr, 0, 2) << endl;

    return 0;
}

