#include <bits/stdc++.h>
using namespace std;

vector<int> failure(string& s){
    int len = (int)s.size();
    vector<int> f(len);
    int j = 0;
    for (int i = 1; i < len; ++i){
        while (j > 0 && s[i] != s[j]) j = f[j-1];
        if (s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

bool kmp(string& a, string& b){
    vector<int> f = failure(b);
    int j = 0;
    int len = (int)a.size();
    for (int i = 0; i < len; ++i){
        while (j > 0 && a[i] != b[j]) j = f[j-1];
        if (a[i] == b[j]) ++j;
        if (j == b.size()) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a,b;
    cin >> a >> b;
    cout << kmp(a,b) << '\n';
    return 0;
}