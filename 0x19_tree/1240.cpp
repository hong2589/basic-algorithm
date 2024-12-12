#include <bits/stdc++.h>
using namespace std;

int n,m;
int dist[1001][1001];
int p[1001];
vector<pair<int,int>> adj[1001];

void bfs(int st){
    queue<int> q;
    q.push(st);
    dist[st][st] = 0;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (auto nxt : adj[cur]){
            int dw,v;
            tie(dw,v) = nxt;
            if (p[cur] == v) continue;
            p[v] = cur;
            dist[st][v] = dist[st][cur] + dw;
            q.push(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n-1; ++i){
        int u,v,c;
        cin >> u >> v >> c;
        adj[u].push_back({c,v});
        adj[v].push_back({c,u});
    }

    for (int i = 1; i <= n; ++i){
        fill(p+1,p+1+n, 0);
        bfs(i);
    }
    while (m--){
        int u,v;
        cin >> u >> v;
        cout << dist[u][v] << '\n';
    }
    
    return 0;
}