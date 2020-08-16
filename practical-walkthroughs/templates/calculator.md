# Template Calculator

### Question

Write a simple calculator program that adds, subtracts, multiplies and divide two numbers using a  class template.

### Explanation

We are asked to create a class template that does the following four functions on two numbers:

1. Add 	2. Subtract	3. Multiply	4. Divide

### Implementation

As all the specified four functions are utility function and the two numbers they work upon can be changed for each call it is better to create a class with static methods instead of a class with instance methods, so that we don't have to instantiate an object every time we need to perform an operation on number.

- First create a Calculator class with template and declare static methods in it:

  ```cpp
  template <typename type>
  class Calculator
  {
      public:
          static type add(type num1, type num2);
          static type subtract(type num1, type num2);
          static type multiply(type num1, type num2);
          static type divide(type num1, type num2);
  };
  ```

- Define each function below the main function:

  - **Note**: When defining the member function outside class we will need to explicitly specify the typename using template syntax.

  ```cpp
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
  ```

- Test our code with the main function:

  - As we are calling a static method we don't need to instantiate an object of the class instead we can call the static method using the template syntax like this

    `ClassName<type>::functionName(params);`

  ```cpp
  int main()
  {    
      cout << Calculator<int>::add(1, 2) << endl;
  
      cout << Calculator<float>::subtract(2.0f, 1.5f) << endl;
  
      cout << Calculator<double>::multiply(100.123, 100.1) << endl;
  
      cout << Calculator<int>::divide(5, 2) << endl;
  
      return 0;
  }
  ```

- We are Done!!



#### Thanks

