#include <bits/stdc++.h>

const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 500 + 5;
bool chk[MX];
int nxt[MX][26];

for (int i = 0; i < MX; ++i){
    fill(nxt[i], nxt[i]+26, -1);
}

int c2i(char c){
    return (int)(c-'A');
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
        if (nxt[cur][c2i(c)] == -1){
            return false;
        }
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