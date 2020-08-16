# Sum Array with Templates

### Question

Write a function template that takes a single type parameter (T) and accepts four function arguments: an array of T, a start index, a stop index (inclusive), and an  optional initial value. 

The function returns the sum of all the array elements in the specified range and the initial value. 

Use the default constructor of T for the default initial value.

 Repeat the exercise but use explicit instantiation to manually create specializations for int data type.



### Explanation

We are asked to create a template function that takes

- One template parameter
- Four function arguments

So the function will look something like this:

```cpp
template <typename type> // one template param
type sumArray(const type arr[], int start, int stop, type initial_value); // four function argument

// start and stop will always be int because they are indices of an array
```



### Implementation

- First define our template function

  ```cpp
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
  ```

  Note:

  - We are returning "type", it will the same data type as of our array elements.

  - the initial value is set using the constructor of the given type, all classes and primitive type have constructor.

    Example:  

    ```cpp
    int num = int();
    cout << num; // num = 0 here
    float decimal = float();
    cout << decimal; // decimal = 0.0 here
    ```

- Explicitly instantiate the sumArray function for int data type:

  Explicitly instantiating a generic function means that a version of that function with the given datatype will always be created by the compiler even we have not used that version.

  [When we call a generic function like this `funcName<type>(args)` ,

  compiler create a version of that function with the given type].

  ```cpp
  // explicit instantiation for int
  template int sumArray<int>(const int arr[], int start, int stop, int initial_value = 0);
  ```

- Test the code in main function:

  ```cpp
  
  int main()
  {
      int intArr[] = {1, 2, 3, 4, 5};
      cout << "int array sum: " << sumArray<int>(intArr, 0, 4, 100) << endl;
  
      float floatArr[] = {1.1f, 2.2f, 3.3f};
      cout << "float array sum: " << sumArray<float>(floatArr, 1, 2) << endl;    // with default initial
  
      double doubleArr[] = {100.1, 200.2, 300.3, 400.4, 500.5};
      cout << "double array sum: " << sumArray(doubleArr, 2, 4, -1000.1) << endl;
      return 0;
  }
  ```

- We can also test our function with a custom class made by us. In that case the type() constructor will call our class constructor and initial value will be set according to that.



#### Thanks

