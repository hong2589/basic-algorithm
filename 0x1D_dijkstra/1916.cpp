#include <bits/stdc++.h>
using namespace std;

#define ARR_LEN 1005

int n,m;
int d[ARR_LEN];
vector<pair<int,int>> adj[ARR_LEN];
const int INF = 0x3f3f3f3f;

void dijkstra(int st){
    fill(d+1, d+1+n, INF);
    d[st] = 0;
    priority_queue< pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> pq;

    pq.push({0,st});
    while (!pq.empty()){
        int w,u,dw,v;
        tie(w,u) = pq.top(); pq.pop();
        if (d[u] != w) continue;
        for (auto nxt : adj[u]){
            tie(dw,v) = nxt;
            if (d[u]+dw < d[v]){
                d[v] = d[u] + dw;
                pq.push({d[v], v});
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
    }

    int st,en;
    cin >> st >> en;
    dijkstra(st);
    cout << d[en] << '\n';
    return 0;
}
    