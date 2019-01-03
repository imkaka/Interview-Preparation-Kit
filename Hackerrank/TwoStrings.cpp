#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {

    int flag[26] = {0};
    int flag2[26] = {0};

    for(int i=0;i<s1.size();i++){
        flag[s1[i]-'a']++;
    }

    for(int i=0;i<s2.size();i++){
        flag2[s2[i]-'a']++;
    }

    for(int i=0; i< 26;i++){
        if(flag[i] >0 && flag2[i] > 0)
          return "YES";
    }

    return "NO";

}

int main()
{


    int q;
    cin >> q;

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        cout << result << "\n";
    }


    return 0;
}
