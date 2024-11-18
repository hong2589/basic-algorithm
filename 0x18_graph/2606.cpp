#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> adj[101];
    int n,m;
    cin >> n >> m;
    while (m--){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    bool vis[101];
    int cnt;
    fill(vis+1, vis+n+1, 0);
    
    q.push(1);
    vis[1] = true;
    cnt = 1;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int nxt : adj[cur]){
            if (vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
            cnt += 1;
        }
    }
    cout << cnt-1 << '\n';
    return 0;
}