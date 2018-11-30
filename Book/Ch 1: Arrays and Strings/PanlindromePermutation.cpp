/*
 Problem:
  Given a string, write a function to check if it is a permutation of a
  palindrome. A palindrome is a word or phrase that is the same forwards and backwards.
  A permutation is a rearrangement of letters. The palindrome does not need to be
  limited to just dictionary words.

 Implementation:
  Count the alphabhet count and return true if odd_counts is not greater than 1.

 Time Complexity: O(n).
 Space Complexity: O(1).

*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool is_perm_of_palindrome(const string& s)
{
    size_t count[128] = {0};
    int odd_counts = 0;

    for (const char& c : s)
        if (isalpha(c))
            ++count[tolower(c)];

    for (char c = 'a'; c <= 'z'; c++)
        if (count[c] % 2) // count is odd
            ++odd_counts;

    return odd_counts <= 1;
}

int main()
{
    cout << is_perm_of_palindrome("Tact Coa") << endl;
    cout << is_perm_of_palindrome("aaa") << endl;
    cout << is_perm_of_palindrome("bad") <<endl;
    cout << is_perm_of_palindrome("tactcoapapa") << endl;
    cout << is_perm_of_palindrome("") << endl;

    return 0;
}
