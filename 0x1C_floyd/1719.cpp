#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
vector<pair<int,int>> adj[201];
int d[201][201];
int nxt[201][201];

void dijkstra(int st){
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    d[st][st] = 0;
    pq.push({0,st});
    while (!pq.empty()){
        int w,u;
        tie(w,u) = pq.top(); pq.pop();
        if (d[st][u] != w) continue;
        for (auto [dw,v] : adj[u]){
            if (w+dw < d[st][v]){
                d[st][v] = w+dw;
                if (u != st) nxt[st][v] = nxt[st][u];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    while (m--){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
        nxt[u][v] = v;
        nxt[v][u] = u;
    }
    for (int i = 1; i <= n; ++i){
        fill(d[i]+1, d[i]+1+n, INF);
        dijkstra(i);
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (i == j) cout << "- ";
            else cout << nxt[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
