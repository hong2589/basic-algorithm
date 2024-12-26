#include <bits/stdc++.h>
using namespace std;

vector<int> failure(string& s){
    int len = (int)s.size();
    int j = 0;
    vector<int> f(len);
    for (int i = 1; i < len; ++i){
        while (j > 0 && s[i] != s[j]) j = f[j-1];
        if (s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

vector<int> kmp(string& a, string& b){
    int len_a = (int)a.size();
    int len_b = (int)b.size();
    vector<int> f = failure(b);

    // cout << "f : ";
    // for (int x : f) cout << x << ' ';
    // cout << '\n';

    vector<int> res;
    int j = 0;
    for (int i = 0; i < len_a; ++i){
        while (j > 0 && a[i] != b[j]) j = f[j-1];
        if (a[i] == b[j]){
            ++j;
        }
        if (j == len_b){
            res.push_back(i - (len_b-1) + 1);
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a,b;
    getline(cin, a);
    getline(cin, b);
    
    vector<int> ans = kmp(a,b);
    cout << ans.size() << '\n';
    for (int idx : ans) cout << idx << ' ';
    cout << '\n';
    return 0;
}