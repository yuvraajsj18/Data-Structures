# Postfix Expression Evaluation

Write a program that performs postfix evaluation using stacks.

#### Algorithm:
  ```
    1. Empty the operand stack.
    2. while not end of input:
    3.    symb := next input character
    4.    if symb is an operand:
    5.        push the symb onto stack
    6.    else if the symb is an operator:
    7.        operator2 = pop the stack
    8.        operator1 = pop the stack
    9.        evaluate the operation
    10.       push the result onto the stack
    11. Pop the stack and return result.
  ```