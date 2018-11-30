/*
 Problem:
  Assume you have a method isSubstring which checks if one word is a substring of
  another. Given two strings, s1 and s2, write code to check if s2 is a rotation
  of s1 using only one call to isSubstring.

 Implementation:
  Concatenate s2 to itself, and check if s1 is a substring of the result. If so, return true. Otherwise, return false.

 Time Complexity: O(N)
 Space Complexity: O(N).

*/

#include<iostream>
#include<string>

using namespace std;

bool is_rotation(const string& s1, const string& s2){

    if(s1.size() == s2.size() && s1.size() > 0){
        string result = s2;
        result += s2;
        return (result.find(s1) != string::npos); //npos == -1
    }
    return false;
}

int main(){
    cout << is_rotation("waterbottle", "erbottlewat") << endl;
    cout << is_rotation("abc", "def") << endl;
    cout << is_rotation("c++", "+c+") << endl;

    return 0;
}
