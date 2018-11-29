/*
 Problem:
  Write a method to replace all spaces in a string with %20. You may assume that the
  string has sufficient space at the end to hold the additional characters, and that
  you are given the "true" length of the string.

 Implementation:
  Count Spaces and make space for 3 chars in place of one space.

 Time Complexity: O(n) as we traverse the whole string.
 Space Complexity: O(1)

*/

#include <string>
#include <iostream>

using namespace std;

string urlify(string& s, int true_len)
{
    int first_space_idx = -1;
    int num_spaces = 0;

    for (int i = 0; i < true_len; i++)
    {
        if (s[i] == ' ')
        {
            if (num_spaces == 0)
                first_space_idx = i;
            ++num_spaces;
        }
    }

    if (num_spaces == 0)
        return s;

    for (int i = (true_len - 1); i > first_space_idx; i--)
    {
        if (s[i] == ' ')
        {
            --num_spaces;
            continue;
        }
        s[i + 2 * num_spaces] = s[i];
        s[i] = ' ';
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            s[i] = '%';
            s[i + 1] = '2';
            s[i + 2] = '0';
        }
    }

    return s;
}

int main()
{
    string s1(" hi  ");
    string s2("Mr John Smith    ");
    string s3("foo");
    string s4("   ");
    cout << urlify(s1, 3) << endl;
    cout << urlify(s2, 13) << endl;
    cout << urlify(s3, 3) << endl;
    cout << urlify(s4, 3) << endl;
    return 0;
}
