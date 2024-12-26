#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n,m;
int dist[20001];
vector<pair<int,int>> adj[20001];

void dijkstra(int st){
    fill(dist+1, dist+1+n, INF);
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    
    dist[st] = 0;
    pq.push({0,st});
    while (!pq.empty()){
        int w,u;
        tie(w,u) = pq.top(); pq.pop();
        if (dist[u] != w) continue;
        for (auto [dw,v] : adj[u]){
            if (dist[u]+dw < dist[v]){
                dist[v] = dist[u]+dw;
                pq.push({dist[u]+dw, v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int st;
    cin >> n >> m >> st;
    while (m--){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }

    dijkstra(st);
    for (int i = 1; i <= n; ++i){
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
    return 0;
}