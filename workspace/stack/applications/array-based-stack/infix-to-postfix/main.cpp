// Convert an infix expression to postfix expression

#include <iostream>
#include "stack.h"
using namespace std;

string get_postfix(string infix);
bool is_operand(char ch);
bool is_operator(char ch);
bool is_lower_precedence(char left, char right);

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    string postfix = get_postfix(infix);

    cout << "Postfix equivalent is " << postfix << endl;

    return 0;
}


string get_postfix(string infix)
{
    Stack<char, 100> operator_stack;
    string postfix = "";

    int len_infix = infix.length();
    for (int i = 0; i < len_infix; i++)
    {
        char symbol = infix[i];
        if (is_operand(symbol))
        {
            postfix += infix[i];
        }
        else if (symbol == '(')
        {
            operator_stack.push(symbol);
        }    
        else if(symbol == ')')
        {
            char popped_operator;
            while ((popped_operator = operator_stack.pop()) != '(')
            {
                postfix += popped_operator;
            }
        }
        else if (is_operator(symbol))
        {
            if (operator_stack.is_empty() || operator_stack.get_top_element() == '(' || is_lower_precedence(operator_stack.get_top_element(), symbol))
            {
                operator_stack.push(symbol);
            }
            else
            {
                postfix += operator_stack.pop();
                operator_stack.push(symbol);
            }
        }
        else
        {
            cout << "Invalid input" << endl;
            exit(1);
        }
        
    }

    while(!operator_stack.is_empty())
        postfix += operator_stack.pop();

    return postfix;
}

bool is_operand(char ch)
{
    return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}

bool is_operator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

bool is_lower_precedence(char left, char right) // returns true if right is of lower precedence then left
{
    int plus = 1;
    int minus = 1;
    int multiply = 2;
    int divide = 2;
    int power = 3;

    switch(left)
    {
        case '+':
        case '-':
            switch(right)
            {
                case '*':
                case '/':
                case '^':
                    return true;
                default:
                    return false;
            }
        break;
        case '*':
        case '/':
            switch(right)
            {
                case '^':
                    return true;
                default:
                    return false;
            }
        break;
        case '^':
            return false;
        break;
        default:
            return false;
    }
}


