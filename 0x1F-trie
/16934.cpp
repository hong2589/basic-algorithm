#include <bits/stdc++.h>
using namespace std;

const int MX = 100001 * 15;
const int ROOT = 1;
int nxt[MX][26];
int cnt[MX];
int c2i(char c){ return c - 'a'; }
int unused = 2;

string nickname(string& name){
    int cur = ROOT;
    string res = "";
    bool chk = true;
    for (int i = 0; i < name.size(); ++i){
        char c = name[i];
        if (chk) res += c;
        if (nxt[cur][c2i(c)] == 0){
            nxt[cur][c2i(c)] = unused++;
            chk = false;
        }
        cur = nxt[cur][c2i(c)];
    }
    if (cnt[cur] == 0) cnt[cur] = 1;
    else {
        cnt[cur]++;
        res += to_string(cnt[cur]);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--){
        string name;
        cin >> name;
        cout << nickname(name) << '\n';
    }
    return 0;
}