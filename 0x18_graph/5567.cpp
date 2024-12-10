#include <bits/stdc++.h>
using namespace std;

vector<int> adj[501];
int dist[501];

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

    queue<int> q;
    fill(dist+2, dist+1+n, -1);
    dist[1] = 0;
    q.push(1);

    int cnt = 0;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int nxt : adj[cur]){
            if (dist[nxt] >= 0) continue;
            dist[nxt] = dist[cur] + 1;
            if (dist[nxt] == 1 || dist[nxt] == 2) ++cnt;
            q.push(nxt);
        }
    }

    cout << cnt << '\n';
    return 0;
}