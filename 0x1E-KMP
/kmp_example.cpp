#include <bits/stdc++.h>
using namespace std;

// O(|a| * |b|)
bool find(string& a, string& b){
    for (int st = 0; st < (int)(a.size()-b.size()); ++st){
        bool match = true;
        for (int i = 0; i < b.size(); ++i){
            if (a[st+i] != b[i]){
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    return false;
}

vector<int> failure(string& s){
    vector<int> f(s.size()); // initialize to f = {0, 0, 0, ..., 0}
    int j = 0;
    for (int i = 1; i < s.size(); ++i){ // start with i = 1, not 0
        while (j > 0 && s[i] != s[j]) j = f[j-1];
        if (s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

bool kmp(string& a, string& b){
    vector<int> f = failure(b);
    int j = 0;
    for (int i = 0; i < (int)a.size(); ++i){
        while (j > 0 && a[i] != b[j]) j = f[j-1];
        if (a[i] == b[j]) j++;
        if (j == b.size()) return true;
    }
    return false;
}

int main(){
    string s,p;
    cin >> s >> p;
    cout << kmp(s,p) << '\n';
    return 0;
}