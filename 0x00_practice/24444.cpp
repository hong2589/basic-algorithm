#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int ans[100001];
bool vis[100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,r;
    cin >> n >> m >> r;
    while (m--){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) sort(adj[i].begin(), adj[i].end());

    queue<int> q;
    int cnt = 0;
    q.push(r);
    vis[r] = true;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        ans[cur] = ++cnt;
        for (int nxt : adj[cur]){
            if (vis[nxt]) continue;
            vis[nxt] = true;
            q.push(nxt);
        }
    }

    for (int i = 1; i <= n; ++i){
        cout << ans[i] << '\n';
    }
    return 0;
}