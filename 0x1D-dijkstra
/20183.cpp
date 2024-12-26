#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MX = 500001;

int n,m,st,en;
ll bal;

vector<pair<ll,int>> adj[MX];
ll d[MX];

ll lo = 1;
ll hi;

bool solve(ll lim){
    fill(d+1, d+1+n, INF);
    priority_queue<pair<ll,int>,
                   vector<pair<ll,int>>,
                   greater<pair<ll,int>>> pq;
    pq.push({0,st});
    d[st] = 0;
    while (!pq.empty()){
        int u,v;
        ll w,dw;
        tie(w,u) = pq.top();
        pq.pop();
        if (d[u] != w) continue;
        for (auto nxt : adj[u]){
            tie(dw,v) = nxt;
            if (dw > lim) continue;
            if (w+dw < d[v]){
                d[v] = w+dw;
                pq.push({d[v],v});
            }
        }
    }

    return d[en] <= bal;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m >> st >> en >> bal;
    while (m--){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
        hi = max(hi,w);
    }

    while (lo < hi){
        ll mid = (lo+hi)/2;
        if (solve(mid)) hi = mid;
        else lo = mid+1;
    }

    if (solve(lo)) cout << lo << '\n';
    else cout << "-1\n";
    return 0;
}