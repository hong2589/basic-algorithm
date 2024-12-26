#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    unordered_set<string> set;
    cin >> str;
    int str_len = str.length();
    for (int len = 1; len <= str_len; len++){
        for (int i = 0; i + len <= str_len; i++){
            string subString = str.substr(i, len);
            set.insert(subString);
        }
    }
    cout << set.size() << '\n';
    return 0;
}