#include <bits/stdc++.h>
using namespace std;

const int MX = 10000 * 500 + 5;
const int ROOT = 1;
int unused = 2;
int nxt[MX][26];
bool chk[MX];
int n,m;

int c2i(char c){
    return c-'a';
}

void insert(string& s){
    int cur = ROOT;
    for (auto c : s){
        if (nxt[cur][c2i(c)] == -1){
            nxt[cur][c2i(c)] = unused++;
        }
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = true;
}

bool find(string& s){
    int cur = ROOT;
    for (auto c : s){
        if (nxt[cur][c2i(c)] == -1) return false;
        cur = nxt[cur][c2i(c)];
    }
    return chk[cur];
}

void erase(string& s){
    int cur = ROOT;
    for (auto c : s){
        if (nxt[cur][c2i(c)] == -1) return;
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < MX; ++i) fill(nxt[i], nxt[i]+26, -1);
    while (n--){
        string input;
        cin >> input;
        insert(input);
    }

    int ans = 0;
    while (m--){
        string p;
        cin >> p;
        if (find(p)) ans++;
    }
    cout << ans << '\n';
    return 0;
}