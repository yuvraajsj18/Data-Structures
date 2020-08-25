# Postfix Expression Evaluation

Write a program that performs postfix evaluation using stacks.

## Explanation

We are asked to write a program that evaluates a **postfix expression**  using array implementation of a stack.

#### What is postfix expression?

Postfix notation is a mathematical notation in which *operators* follow their *operands*.

Examples:

| Infix Expression | Postfix Expression |
| ---------------- | ------------------ |
| 3 + 4            | 3 4 +              |
| 3 - 4 + 5        | 3 4 - 5 +          |
| 3 - (4 * 5)      | 3 4 5 * -          |
| (3 - 4) * 5      | 3 4 - 5 *          |

*An advantage of using Postfix notation is that it removes the need for parenthesis that are required by infix notation*.

We can evaluate a postfix expression using a stack with the following algorithm.

#### Algorithm:
  ```pseudocode
Empty the operand stack.
while not end of input:
	symb := next input character
    if symb is an operand:
    	push the symb onto stack
    else if the symb is an operator:
     	operator2 = pop the stack
    	operator1 = pop the stack
    	evaluate the operation
    	push the result onto the stack
Pop the stack and return result.
  ```

## Implementation

### Creating a stack

First thing we will need to solve this problem is a stack, we will be reusing the same stack we implemented [here](./stack.md), but for completion purposes let's rewrite the code here and you can look the explanation on its respective article provided above.

#### stack.h

- This is header file for our stack template class.

```cpp
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename type, int size>
class Stack
{
    private:
        type* stack; // stack is a dynamically allocated array that will contains all our elements.
        int top;    // index of top element in stack

    public:
        Stack();
        ~Stack();

        bool is_empty();    // Return true if stack is empty, false otherwise.
        void push(type element);    // insert 'element' at the top of stack, if not overflow
        type pop();     // remove element at the top of stack if not underflow
        void display();     // print all elements in stack to console 
        type get_top_element();     // returns the top element
        void clear();       // remove all elements in the stack and reset top.
};

#include "stack.tpp"
#endif
```

#### stack.tpp

- This is the implementation file for our stack template class.
- Files for template classes have .tpp extension instead of .cpp by convention.

```cpp
#include "stack.h"

// member functions of Stack

template <typename type, int size>
Stack<type, size> :: Stack()
{
    // create a stack with array of size - 'size'
    stack = new type[size];
    top = -1;   // -1 indicates that there is not element in stack at this moment
}

template <typename type, int size>
Stack<type, size> :: ~Stack()
{
    // free the memory occupied by dynamic array of stack
    delete[] stack;
}

// Return true if stack is empty, false otherwise.
template<typename type, int size>
bool Stack<type, size> :: is_empty()
{
    // stack is empty when top is -1
    return top == -1;   
}

// insert 'element' at the top of stack, if not overflow
template<typename type, int size>
void Stack<type, size> :: push(type element)
{
    // checks for overflow
    if (top == size - 1)
    {
        throw out_of_range("Stack Overflow!! No more space to add elements.");
    }

    // insert element on next position in array
    stack[++top] = element; 
}

// Remove element at the top of stack if not underflow
template<typename type, int size>
type Stack<type, size> :: pop()
{
    // check for underflow
    if (is_empty())
    {
        throw out_of_range("Stack Underflow!! No more element to pop.");
    }

    // pop element
    type element_popped = stack[top--];
    return element_popped;
}

// print all elements in stack to console 
template<typename type, int size>
void Stack<type, size> :: display()
{
    // check for empty stack
    if (is_empty())
    {
        cout << "Woops! stack is empty." << endl;
        return;
    }

    // loop over stack and display all elements
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

// Returns the top element
template <typename type, int size>
type Stack<type, size> :: get_top_element()
{
    if (is_empty())
    {
        throw out_of_range("Stack is empty!!");
    }
    return stack[top];
}

// Remove all elements in the stack and reset it.
template <typename type, int size>
void Stack<type, size> :: clear()
{
    // free current memory occupied by the stack
    delete[] stack;
    // reset top
    top = -1;
    // assign new memory
    stack = new type[size];
}
```

- Once again, if you want any explanation for the code above, it is given [here](./stack.md).

## evalPostfix.cpp

- This is the main file for our program.

- This contains the following functions to carry out the postfix evaluation:
  - **main**: Contains the driver code for our program.
  - **eval_postfix_expression**: Evaluates a postfix expression as per our algorithm.
  - **Helper function**:
    - **isOperator**: Returns true if given string input is an operator that is +, - , *, /, ^.
    - **isOperand**: Returns true if given string input is an operand that is it is a number.
    - **eval**: Returns the result of operator applied on two numbers.
  
- Lets Implement all the functions.
  - **eval_postfix_expression**: Evaluates a postfix expression as per our algorithm and returns the result.
    - It takes a string input of *expression* and returns a double value that is our result of expression.
    - The maximum size of stack used is taken to be 100.
    - a while loop is used to take operand and operators from string so that we can also input numbers with more than one digit.
    - Operators and operands must be separated by atleast one space in the input string.

  ```cpp
  double eval_postfix_expression(string expression)
  {
      // create an empty operand stack
      // let the size of stack be length of string as it can't be more than that
      const int operand_stack_size = expression.length();
      Stack<double, 100> operand_stack;
  
      // evaluate
      for (int i = 0; i < operand_stack_size; i++)
      {
          // get the next symbol from stack - operand or operator
          string symbol = "";
          while (expression[i] != ' ' && i != operand_stack_size)     // keep adding until space is encountered or the string ends
          {
              symbol += expression[i];
              i++;
          }
  
          if (symbol == "")   // if space is encountered more than once then skip it.
          {
              continue;
          }
          if (isOperand(symbol))
          {
              operand_stack.push(stod(symbol));   // stod converts a string to double value
          }
          else if (isOperator(symbol))
          {
              double operand2 = operand_stack.pop();
              double operand1 = operand_stack.pop();
              double result = eval(symbol, operand1, operand2);
              operand_stack.push(result);
          }
          else 
          {
              cout << "Invalid Expression" << endl;
              exit(1);
          }
      }
  
      // return the final result
      return operand_stack.pop();
  }
  ```

  - **Helper Functions**:

    - *eval*: Perform a specific operation on two operands.

    ```cpp
    double eval(string operator_, double operand1, double operand2)
    {
        switch(operator_[0])
        {
            case '+':
                return operand1 + operand2;
            break;
            case '-':
                return operand1 - operand2;
            break;
            case '*':
                return operand1 * operand2;
            break;
            case '/':
                return operand1 / operand2;
            break;
            case '^':
                return pow(operand1, operand2);
            break;
            default:
                cout << "Invalid operator" << endl;
                exit(1);
        }
    }
    ```

    - *isOperand*: Checks if an string is a operand by checking that it's first character is a digit.

    ```cpp
    bool isOperand(string characters)
    {
        int firstDigit = characters[0] - '0';
        if (firstDigit >= 0 && firstDigit <= 9)
            return true;
        return false;
    }
    ```

    - *isOperator*: Checks if the given character is an operator.
      - This will return true if character is any one of +, -, /, *, ^.

  ```cpp
  bool isOperator(string character)
  {
      return character == "+" || character == "-" ||  character == "*" || character == "/"  || character == "^";
  }
  ```

- **Main Function**: Takes a postfix expression as input from user and evaluates it.

  ```cpp
  int main()
  {
      string expression;
      cout << "Enter postfix expression: ";
      getline(cin, expression);
  
      cout << expression << endl;
  
      double result = eval_postfix_expression(expression);
      cout << "Result = " << result << endl;
  
      return 0;
  }
  ```

- *Don't forgot to include the following header files and declare the following functions*:

  ```cpp
  #include <iostream>
  #include <string>
  #include <cmath>
  #include "stack.h"
  
  using namespace std;
  
  double eval_postfix_expression(string expression);
  bool isOperator(string character);
  bool isOperand(string characters);
  double eval(string operator_, double operand1, double operand2);
  ```

  


















