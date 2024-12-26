#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
const int MX = 1000 * 15 + 5;
map<string,int> nxt[MX];
int depth[MX];
int unused = 2;

void insert(vector<string>& foods){
    int cur = ROOT;
    for (string food : foods){
        if (nxt[cur].find(food) == nxt[cur].end()){
            nxt[cur][food] = unused++;
            depth[nxt[cur][food]] = depth[cur]+1;
        }
        cur = nxt[cur][food];
    }
}

void show(int cur){
    for (auto nxtNode : nxt[cur]){
        string name = nxtNode.first;
        int nxtIdx = nxtNode.second;
        for (int i = 0; i < 2*(depth[nxtIdx]-1); ++i) cout << '-';
        cout << name << '\n';
        show(nxtIdx);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--){
        int m;
        cin >> m;

        vector<string> foods;
        while (m--){
            string food;
            cin >> food;
            foods.push_back(food);
        }
        insert(foods);
    }

    show(1);
    return 0;
}