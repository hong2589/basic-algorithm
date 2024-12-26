#include <bits/stdc++.h>
using namespace std;

const int MX = 10000 * 501;
const int ROOT = 1;
int unused = 2;
int c2i(char c){ return c - 'a';}
int nxt[MX][26];
void insert(string& s){
    int cur = ROOT;
    for (auto c : s){
        if (nxt[cur][c2i(c)] == -1) nxt[cur][c2i(c)] = unused++;
        cur = nxt[cur][c2i(c)];
    }
}

bool find(string& s){
    int cur = ROOT;
    for (auto c : s){
        if (nxt[cur][c2i(c)] == -1) return false;
        cur = nxt[cur][c2i(c)];
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for (int i = 0; i < MX; ++i) fill(nxt[i], nxt[i]+26, -1);
    while (n--){
        string s;
        cin >> s;
        insert(s);
    }

    int ans = 0;
    while (m--){
        string s;
        cin >> s;
        if (find(s)) ++ans;
    }
    cout << ans << '\n';

    return 0;
}
