#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
const int MX = 10000 * 10 + 5;
int unused = 2;
int nxt[MX][10];
int chk[MX];

bool comp(string& a, string& b){
    int len1 = a.length();
    int len2 = b.length();
    if (len1 > len2) return true;
    else if (len1 < len2) return false;
    else {
        return a > b;
    }
}

char c2i(char c){
    return c-'0';
}

void insert(string& s){
    int cur = ROOT;
    for (auto c : s){
        cout << c2i(c) << '\n';
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
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--){
        int n;
        vector<string> list;

        cin >> n;
        
        unused = 2;
        while (n--){
            string s;
            cin >> s;
            list.push_back(s);
        }

        bool ans = true;
        for (int i = 0; i < MX; ++i) {
            fill(nxt[i], nxt[i]+10, -1);
            fill(chk, chk+MX, 0);
        }
        sort(list.begin(), list.end(), comp);
        for (string s : list){
            if (!find(s)){
                insert(s);
            }
            else {
                ans = false;
                break;
            }
        }
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}