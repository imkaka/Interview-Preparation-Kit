/*
 Problem:
  There are three types of edits that can be performed on strings: insert a character,
  remove a character, or replace a character. Given two strings, write a function to
  check if they are one edit (or zero edits) away.

 Implementation:
  Insert and Remove are both same action as we see the strings and replace is done when length is
  same.

 Time Complexity: O(min(len(s1),len(s2))
 Space Complexity: O(1).

*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool one_edit_away(const string& s1, const string& s2)
{
    const string& longest = (s1.size() > s2.size()) ? s1 : s2;
    const string& shortest = (s1.size() > s2.size()) ? s2 : s1;

    size_t edits = 0;

    if (longest.size() == shortest.size())
    {
        for (int i = 0; i < longest.size(); i++)
            if (s1[i] != s2[i])
                ++edits;
    }
    else if ((longest.size() - shortest.size()) > 1)
    {
        edits = longest.size() - shortest.size();
    }
    else // strings are only one character apart in length
    {
        for (int i = 0, j = 0; i < shortest.size() && j < longest.size(); i++, j++)
        {
            if (shortest[i] != longest[j])   // we assume this is the character
                                             // missing from shortest
            {
                ++j;
                ++edits;

            }
        }
    }

    return (edits <= 1);
}

int main()
{
    cout << one_edit_away("pale", "ple") << endl
        << one_edit_away("pales", "pale") << endl
        << one_edit_away("pale", "bale") << endl
        << one_edit_away("pale", "bake") << endl
        << one_edit_away("", "a") << endl;
    return 0;
}


