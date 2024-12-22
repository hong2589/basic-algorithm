#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
vector<pair<int,int>> adj[251];
int d[251][251];
void dijkstra(int st){
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    d[st][st] = 0;
    pq.push({0,st});
    while (!pq.empty()){
        int w,u,dw,v;
        tie(w,u) = pq.top(); pq.pop();
        if (d[st][u] != w) continue;
        for (auto nxt : adj[u]){
            tie(dw,v) = nxt;
            if (w+dw < d[st][v]){
                d[st][v] = w+dw;
                pq.push({d[st][v] ,v});
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
        int u,v,b;
        cin >> u >> v >> b;
        adj[u].push_back({0, v});
        adj[v].push_back({!b, u});
    }

    for (int i = 1; i <= n; ++i){
        fill(d[i]+1, d[i]+1+n, INF);
        dijkstra(i);
    }

    int k;
    cin >> k;
    while (k--){
        int st,en;
        cin >> st >> en;
        cout << d[st][en] << '\n';
    }

    return 0;
}