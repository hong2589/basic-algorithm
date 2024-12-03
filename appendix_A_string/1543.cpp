#include <bits/stdc++.h>
using namespace std;

int solve(string& s, string& p){
    int cur = 0;
    int ans = 0;
    while (cur < s.size()){
        cout << "cur : " << cur << '\n';
        int nxt = s.substr(cur).find(p);
        if (nxt == string::npos) break;
        ++ans;
        cur = nxt + p.size();
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    string p;
    getline(cin, s);
    getline(cin, p);

    cout << solve(s,p) << '\n';

    return 0;
}