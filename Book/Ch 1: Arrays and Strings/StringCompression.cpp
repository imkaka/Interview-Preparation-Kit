/*
 Problem:
  Implement a method to perform basic string compression using the counts of
  repeated characters. For example, the string aabcccccaaa would because a2b1c5ae. If
  the "compressed" string would not become smaller than the original string, your method
  should return the original string. You can assume the string has only uppercase and
  lowercase letters.

 Implementation:
  We can just iterate over given string to build the compressed string counting the duplicates.

 Time Complexity: O(n)
 Space Complexity: O(n).

*/

#include <string>
#include <iostream>

using namespace std;

void append_compression(string& s, char c, size_t counter){
    s.push_back(c);
    s.append(to_string(counter));
}

string compress(const string& s)
{
    if (s.size() == 0)
        return s;

    size_t counter = 0;
    char current = s[0];
    string result = string();

    for (char c : s)
    {
        if (c == current)
        {
            ++counter;
        }
        else
        {
            append_compression(result, current, counter);
            current = c;
            counter = 1;
        }
    }
    append_compression(result, current, counter);

    if (result.size() >= s.size())
        return s;

    return result;
}

int main()
{
    cout << compress("test") << endl;
    cout << compress("aabcccccaaa") << endl;
    cout << compress("a") << endl;
    cout << compress("") << endl;

    return 0;
}
