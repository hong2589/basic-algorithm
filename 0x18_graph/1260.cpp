#include <bits/stdc++.h>
using namespace std;

int n,m,st;
vector<int> adj[1001];
bool vis[1001];

void dfs(int cur){
    vis[cur] = true;
    cout << cur << ' ';
    for (int nxt : adj[cur]){
        if (vis[nxt]) continue;
        dfs(nxt);
    }
}

void bfs(int cur){
    queue<int> q;
    q.push(cur);
    vis[cur] = true;
    while (!q.empty()){
        int x = q.front();
        cout << x << ' ';
        q.pop();
        for (int nxt : adj[x]){
            if (vis[nxt]) continue;
            vis[nxt] = true;
            q.push(nxt);
        }
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> st;
    while (m--){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i){
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(st);
    cout << '\n';
    fill(vis+1, vis+1+n, false);
    bfs(st);

    return 0;
}