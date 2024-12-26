#include <bits/stdc++.h>
using namespace std;

#define ARR_LEN 805

int n,m;
int d[ARR_LEN][ARR_LEN];
vector<pair<int,int>> adj[ARR_LEN];
const int INF = 0x3f3f3f3f;

void dijkstra(int st){
    fill(d[st]+1, d[st]+1+n, INF);
    d[st][st] = 0;
    priority_queue< pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> pq;

    pq.push({0, st});
    while (!pq.empty()){
        int w,u,dw,v;
        tie(w,u) = pq.top(); pq.pop();
        if (d[st][u] != w) continue;
        for (auto nxt : adj[u]){
            tie(dw,v) = nxt;
            if (d[st][u]+dw < d[st][v]){
                d[st][v] = d[st][u]+dw;
                pq.push({d[st][v], v});
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--){
        int u,v,c;
        cin >> u >> v >> c;
        adj[u].push_back({c,v});
        adj[v].push_back({c,u});
    }

    for (int i = 1; i <= n; ++i){
        dijkstra(i);
    }

    int st, mid1, mid2, en;
    st = 1;
    en = n;
    cin >> mid1 >> mid2;
    if (d[st][mid1] == INF || d[mid1][mid2] == INF || d[mid2][en] == INF) cout << "-1\n";
    else {
        int a = d[st][mid1]+d[mid1][mid2]+d[mid2][en];
        int b = d[st][mid2]+d[mid2][mid1]+d[mid1][en];
        cout << min(a,b) << '\n';
    }
    return 0;
}