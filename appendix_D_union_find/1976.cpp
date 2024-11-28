#include <bits/stdc++.h>
using namespace std;

vector<int> p(201,-1);
int find(int x){
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v){
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (p[v] < p[u]) swap(u,v);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            int x;
            cin >> x;
            if (x == 1){
                uni(i,j);
            }
        }
    }

    bool possible = true;
    while (m--){
        
    }
}