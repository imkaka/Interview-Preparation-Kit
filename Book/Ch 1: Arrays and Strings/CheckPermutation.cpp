/*
 Problem:
 Given two strings, write a method to decide if one is a permutation of the
 other.

 Implementation:
  Sort both strings and compare the two. If they're equal, they're
  permutations of each other.

 Time Complexity: O(a * log(a) + b * log(b)) where a is the length of the first string and b is the length of the second string.

 Space Complexity: Many implementations of std::sort rely on a hybrid of merge sort and
  quicksort, so roughly O(log(n)) or O(n).

*/

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

bool is_permutation(string s1, string s2)
{
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main()
{
    cout << is_permutation("hello", "lleoh") << endl;
    cout << is_permutation("one", "two") << endl;
    cout << is_permutation("a", "a") << endl;
    cout << is_permutation("!@", "@!") << endl;
    return 0;
}
