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
bool isUniq(string& s, string& p){
    vector<int> f = failure(s);
    int j = 0;
    bool found = false;
    for (int i = 0; i < s.size(); ++i){
        while (j > 0 && s[i] != p[j]) j = f[j-1];
        if (s[i] == p[j]) ++j;
        if (j == p.size()){
            if (found){
                return false;
            }
            j = f[j-1];
            found = true;
        }
    }
    return found;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--){
        string a,w,s;
        cin >> a >> w >> s;

        vector<int> ans;
        for (int shift = 0; shift < a.size(); ++shift){
            // mapping
            unordered_map<char,char> tbl;
            string target = a.substr(a.size()-shift, shift) + a.substr(0, a.size()-shift);
            for (int i = 0; i < a.size(); ++i){
                tbl[a[i]] = target[i];
            }
            
            // shifting
            string s_cp = "";
            for (int i = 0; i < s.size(); ++i){
                s_cp += tbl[s[i]];
            }
            if (isUniq(s_cp, w)){
                ans.push_back(shift);
            }
        }

        // answer
        if (ans.empty()){
            cout << "no solution\n";
        }
        else if (ans.size() == 1){
            cout << "unique: " << ans[0] << '\n';
        }
        else {
            cout << "ambiguous: ";
            for (int x : ans) cout << x << ' ';
            cout << '\n';
        }
    }

    return 0;
}