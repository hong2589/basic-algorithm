#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    unordered_set<string> S;
    cin >> input;
    for (int len = 1; len <= input.length(); ++len){
        for (int i = 0; i + len <= input.length(); ++i){
            S.insert(input.substr(i,len));
        }
    }

    cout << S.size() << '\n';
    return 0;
}