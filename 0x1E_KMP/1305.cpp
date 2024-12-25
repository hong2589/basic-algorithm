#include <bits/stdc++.h>
using namespace std;

vector<int> failure(string& s){
    vector<int> f(s.size());
    int j = 0;
    for (int i = 1; i < s.size(); ++i){
        while (j > 0 && s[i] != s[j]) j = f[j-1];
        if (s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    cin >> n;
    cin >> s;

    vector<int> f = failure(s);
    cout << n - f[n-1] << '\n';

    return 0;
}