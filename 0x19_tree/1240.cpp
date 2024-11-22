#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[1001]; // adj[u]: {v1, d1}, {v2, d2} ... 
int p[1001];
int dist_to_parent[1001];

void dfs(int cur){
    for (auto [nxt, dist] : adj[cur]){
        if (nxt == p[cur]) continue;
        p[nxt] = cur;
        dist_to_parent[nxt] = dist;
        dfs(nxt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n-1; ++i){
        int u,v,d;
        cin >> u >> v >> d;
        adj[u].push_back({v,d});
        adj[v].push_back({u,d});
    }

    while(m--){
        int u,v;
        cin >> u >> v;
        fill(p+1, p+1+n, 0);
        fill(dist_to_parent+1, dist_to_parent+1+n, 0);
        dfs(u);

        int cur = v;
        int cnt = 0;
        while (cur != u){
            cnt += dist_to_parent[cur];
            cur = p[cur];
        }
        cout << cnt << '\n';
    }
    return 0;
}