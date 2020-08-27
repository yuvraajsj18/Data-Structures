/*
 *  Write a program to add two large numbers using stacks.
 */

#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

string addBigNums(string num1, string num2);

int main()
{
    string num1, num2;
    cout << "Enter First Number: ";
    getline(cin, num1);
    cout << "Enter Second Number: ";
    getline(cin, num2);

    string sum = addBigNums(num1, num2);
    cout << "Sum is " << sum << endl;

    return 0;
}

string addBigNums(string num1, string num2)
{
    // Store num1 on stack
    Stack<int, 100> stack_num1;
    for (int i = 0; i < num1.length(); i++)
    {
        stack_num1.push(num1[i] - '0');
    }

    // store num2 on stack
    Stack<int, 100> stack_num2;
    for (int i = 0; i < num2.length(); i++)
    {
        stack_num2.push(num2[i] - '0');
    }

    // evaluate the sum
    int carry = 0;
    Stack<int, 101> stack_sum;
    while (!(stack_num1.is_empty() && stack_num2.is_empty()))   // while one stack is empty
    {
        int num1, num2;
        // get top element from first stack
        if (!stack_num1.is_empty()) 
            num1 = stack_num1.pop();        
        else
            num1 = 0;   // 0 if no more elements exist

        // get top element from second stack
        if (!stack_num2.is_empty())
            num2 = stack_num2.pop();
        else
            num2 = 0;   // 0 if no more elements exist

        int sum = num1 + num2 + carry;  // add both elements(digits) and the previous carry
        stack_sum.push(sum % 10);   // push unit place digit of sum to result
        carry = sum / 10;  
    }

    if (carry)
        stack_sum.push(carry);

    // convert stack back to string
    string resultSum = "";
    while(!stack_sum.is_empty())
    {
        resultSum += stack_sum.pop() + '0';
    }

    return resultSum;
}