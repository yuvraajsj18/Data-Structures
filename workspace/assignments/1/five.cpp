/*
    Check recursively whether a given word is palindrome or not
*/

#include <iostream>
using namespace std;

bool is_palindrome(string word, int start, int end)
{
    if (start == end)
        return true;
    else if (word[start] != word[end - 1])
        return false;

    return is_palindrome(word, start + 1, end - 1);
}

int main()
{
    string word1 = "Hello";
    string word2 = "ABCCBA";

    cout << boolalpha << is_palindrome(word1, 0, word1.length()) << endl;
    cout << boolalpha << is_palindrome(word2, 0, word2.length()) << endl;

    return 0;
}