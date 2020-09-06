/*
    Write a program to perform delimiter matching.
 */

#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

bool match_delimiters(string content);

int main(int argc, char* argv[])
{
    if (argv[1] && string(argv[1]) == "--help")
    {
        cout << "Delimiter Matching Program" << endl;
        cout << "To run the program, use 1 of the following method:\n";
        cout << "1. ./delimiter < filename\n";
        cout << "2. ./delimiter\n"
             << "then enter your string when prompted.\n"
             << "Press control d(linux)/control z(windows) to mark the end of input.";
        return 0;
    }

    string content;
    cout << "Enter content(Press control d(unix) or control z(windows) to end input):\n";
    getline(cin, content, '\0');

    bool delimiters_matched = match_delimiters(content);

    if (delimiters_matched)
    {
        cout << "\nAll delimiters matched" << endl;
    }
    else
    {
        cout << "\nDelimiters did not match" << endl;
    }
    
    return 0;
}

bool match_delimiters(string content)
{
    int content_length = content.length();

    Stack<char, 100> delimiters_stack;

    for (int i = 0; i < content_length; i++)
    {
        // get the character
        char ch = content[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            delimiters_stack.push(ch);
        }
        else if (ch == '/')
        {
            ch = content[++i];  // read the next character
            if (ch == '*')
            {
                // skip all character until */ is found
                while ((content[i] != '*' & content[++i] != '/') && i < content_length - 1);  

                // if not found return false
                if (i == content_length - 1)
                    return false;
            }
        }
        else if (ch == ')') 
        {   
            char stack_top_ch = delimiters_stack.pop();
            if (stack_top_ch != '(')
                return false;
        }  
        else if (ch == ']')
        {   
            char stack_top_ch = delimiters_stack.pop();
            if (stack_top_ch != '[')
                return false;
        }   
        else if (ch == '}')
        {   
            char stack_top_ch = delimiters_stack.pop();
            if (stack_top_ch != '{')
                return false;
        }    
    }

    if (delimiters_stack.is_empty())
        return true;

    return false;
}