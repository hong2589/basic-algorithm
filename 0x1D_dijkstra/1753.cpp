#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

vector<pair<int,int>> adj[20001]; // <cost, v>
int d[20001];
bool fix[20001];
const int INF = 0x3f3f3f3f;
int n;

void dijkstra_naive(int st){
    fill(d+1, d+1+n, INF);
    d[st] = 0;
    fix[st] = true;
    for (auto nxt : adj[st]){
        d[nxt.Y] = nxt.X;
    }

    for (int cnt = 0; cnt < n-1; ++cnt){
        // Find w not in N such that d[w] is a minimum
        int w = -1;
        int min_dist = INF;
        for (int i = 1; i <= n; ++i){
            if (fix[i]) continue;
            if (d[i] < min_dist){
                min_dist = d[i];
                w = i;
            }
        }
        if (w == -1) break;
        fix[w] = true;

        // Update d[v] = min(d[ ], d[w]+c[w][v])
        for (auto nxt : adj[w]){
            d[nxt.Y] = min(d[nxt.Y], d[w]+nxt.X);
        }
    }
}

void dijkstra_pq(int st){
    fill(d+1, d+1+n, INF);
    priority_queue< pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> pq;
    
    // initial condition
    d[st] = 0;
    pq.push({d[st], st});
    while (!pq.empty()){
        int u_dist, u;
        tie(u_dist, u) = pq.top(); pq.pop();
        if (d[u] != u_dist) continue;
        for (auto nxt : adj[u]){
            int uv_dist = nxt.first;
            int v = nxt.second;
            if (d[u] + uv_dist < d[v]){
                d[v] = d[u] + uv_dist;
                pq.push({d[v], v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m,st;
    cin >> n >> m >> st;
    while (m--){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }

    dijkstra_pq(st);
    for (int i = 1; i <= n; ++i){
        if (d[i] == INF) cout << "INF\n";
        else cout << d[i] << '\n';
    }
    return 0;
}