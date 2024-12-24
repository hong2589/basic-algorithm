#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX = 100'002;
vector<pair<ll,int>> adj[MX];
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll d[MX];
priority_queue<pair<ll,int>,
               vector<pair<ll,int>>,
               greater<pair<ll,int>>> pq;

void dijkstra(){
    while (!pq.empty()){
        int u,v;
        ll w,dw;
        tie(w,u) = pq.top();
        pq.pop();
        if (d[u] != w) continue;
        for (auto nxt : adj[u]){
            tie(dw,v) = nxt;
            if (w+dw < d[v]){
                d[v] = w+dw;
                pq.push({d[v],v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin >> n >> m >> k;
    while (m--){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        adj[v].push_back({w,u});
    }

    fill(d+1, d+1+n, INF);
    for (int i = 0; i < k; ++i){
        int st;
        cin >> st;
        pq.push({0,st});
        d[st] = 0;
    }
    dijkstra();
    
    int idx = max_element(d+1, d+1+n) - d;
    cout << idx << '\n' << d[idx] << '\n';
    return 0;
}