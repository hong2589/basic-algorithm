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
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int x;
            cin >> x;
            if (x == 1){
                uni(i,j);
            }
        }
    }

    bool possible = true;
    int u,v;
    cin >> u;
    --m;
    while (m--){
        cin >> v;
        if (find(u) != find(v)) possible = false;
    }

    if (possible) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}