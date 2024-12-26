#include <bits/stdc++.h>
using namespace std;

const int MX = 500 * 80 + 5;
const int ROOT = 1;
int unused = 2;
map<string,int> nxt[MX]; // <data, next_idx>
int depth[MX];

void insert(string& s){
    vector<string> tokens;
    string token;
    char delimiter = '\\';
    istringstream stream(s);
    while (getline(stream, token, delimiter)){
        tokens.push_back(token);
    }

    int cur = ROOT;
    for (string dir : tokens){
        if (nxt[cur].find(dir) == nxt[cur].end()){
            nxt[cur][dir] = unused++;
            depth[nxt[cur][dir]] = depth[cur]+1;
        }
        cur = nxt[cur][dir];
    }
}

void show(int cur){
    for (auto nxtNode: nxt[cur]){
        string path = nxtNode.first;
        int idx = nxtNode.second;
        for (int i = 0; i < depth[idx]-1; ++i) cout << ' ';
        cout << path << '\n';
        show(idx);
    }
}

int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n--){
        string s;
        cin >> s;
        insert(s);
    }

    show(1);
    return 0;
}