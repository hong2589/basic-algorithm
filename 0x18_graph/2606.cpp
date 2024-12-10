#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
bool vis[101];
int cnt = 0;

void dfs(int cur){
    ++cnt;
    vis[cur] = true;
    for (int nxt : adj[cur]){
        if (vis[nxt]) continue;
        dfs(nxt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    while (m--){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    cout << cnt-1 << '\n';
    return 0;
}