#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
vector<int> p(100001, -1);
int find(int x){
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v){
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (p[u] == p[v]) p[u]--;
    if (p[v] < p[u]) swap(u,v);
    p[v] = u;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int u,v;
        cin >> u >> v;
        if (!uni(u,v)) ++ans;
    }

    for (int i = 2; i <= n; ++i){
        if (uni(1, i)) ++ans;
    }
    cout << ans << '\n';
    return 0;
}