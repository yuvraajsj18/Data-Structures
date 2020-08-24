#include <iostream>
#include <string>
#include <cmath>
#include "stack.h"

using namespace std;

double eval_postfix_expression(string expression);
bool isOperator(string character);
bool isOperand(string characters);
double eval(string operator_, double operand1, double operand2);

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


// Function to evaulate a postfix expression
// the expression has operand and operator - different operand and operators must have atleast 1 space in between
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
        while (expression[i] != ' ' && i != operand_stack_size)
        {
            symbol += expression[i];
            i++;
        }

        if (isOperand(symbol))
        {
            operand_stack.push(stod(symbol));
        }
        else if (isOperator(symbol))
        {
            double operand2 = operand_stack.pop();
            double operand1 = operand_stack.pop();
            double result = eval(symbol, operand1, operand2);
            operand_stack.push(result);
        }
        else if (symbol == " ")
        {
            continue;
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

bool isOperand(string characters)
{
    int firstDigit = characters[0] - '0';
    if (firstDigit >= 0 && firstDigit <= 9)
        return true;
    return false;
}

bool isOperator(string character)
{
    return character == "+" || character == "-" ||  character == "*" || character == "/"  || character == "^";
}