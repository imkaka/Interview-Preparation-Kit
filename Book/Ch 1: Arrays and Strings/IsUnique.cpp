// Pro - Implement a Algorithm to determine if a string has all unique characters.
// What If you cannot use additional data structures.

// Solution
// Time Complexity: O(1)
// Space Complexity: O(1)
//
// Checking for str.length() > 256 lowered our time/space complexity from O(n) to O(1)

#include<iostream>

using namespace std;

const int NUM_CHAR = 256;                   // should ask interviewer if
                                            // String is ASCII or Unicode.
                                            // We assume ASCII.
bool isUniqueChar(string str){

    if (str.size() > NUM_CHAR){
            return false;
        }

    bool mySet[NUM_CHAR] = {false};

    for (int i = 0; i < str.length(); i++){

        if(mySet[str[i]]){
            return false;
        } else{
            mySet[str[i]] = true;
        }
    }
    return true;
}

int main(){

    cout << isUniqueChar("abcahdadadas")<<endl;
    cout<< isUniqueChar("Healt") << endl;
    return 0;
}

// Follow-up Question: What if we're not allowed to use additional data
// structures?
//
// Answer: Can do brute-force O(n^2) runtime O(1) space solution by comparing
// all pairs, or Sort and check the neighbours if same in O(nlogn).
