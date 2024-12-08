#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<string> V = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    for (string cmp : V){
        int cur = s.find(cmp);
        while (cur != string::npos){
            s.replace(cur, cmp.size(), "1");
            cur = s.find(cmp);
        }
    }
    cout << s.size() << '\n';
    return 0;
}