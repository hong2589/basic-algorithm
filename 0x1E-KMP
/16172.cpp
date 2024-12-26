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

bool kmp(string& a, string& b){
    int len_a = (int)a.size();
    int len_b = (int)b.size();
    vector<int> f = failure(b);
    int j = 0;
    for (int i = 0; i < len_a; ++i){
        while (j > 0 && a[i] != b[j]) j = f[j-1];
        if (a[i] == b[j]) ++j;
        if (j == len_b){
            return true;
        }
    }
    return false;
}

string remove_digit(string& a){
    string res = "";
    int len = (int)a.size();
    for (int i = 0; i < len; ++i){
        if (!isdigit(a[i])) res += a[i];
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a,b;
    cin >> a >> b;

    string strip = remove_digit(a);
    cout << kmp(strip, b) << '\n';
    return 0;
}