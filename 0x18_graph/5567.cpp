#include <bits/stdc++.h>
using namespace std;

vector<int> adj[501];

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

    int dist[501];
    fill(dist+1, dist+n+1, -1);
    queue<int> q;
    int cnt = 0;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        if (dist[cur] <= 2) cnt += 1;
        for (int nxt : adj[cur]){
            if (dist[nxt] >= 0) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1; 
        }
    }
    cout << cnt-1 << '\n';
    return 0;
}