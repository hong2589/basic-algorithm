#include <bits/stdc++.h>
using namespace std;

#define ARR_LEN 10001
#define X first
#define Y second

int n = 10;
const int INF = 0x3f3f3f3f;
vector<pair<int,int>> adj[ARR_LEN];
int d[ARR_LEN];
bool fix[ARR_LEN];

void dijkstra_naive(int st){
    fill(d+1, d+1+n, INF);
    d[st] = 0;
    fix[st] = true;
    for (auto nxt : adj[st]){
        d[nxt.second] = nxt.first;
    }

    for (int cnt = 0; cnt < n-1; ++cnt){
        // 1. Find w not in N such that d[w] is a minimum
        int w = -1;
        int min_dist = INF;
        for (int i = 1; i <= n; ++n){
            if (fix[i]) continue;
            if (d[i] < min_dist){
                w = i;
                min_dist = d[i];
            }
        }
        if (w == -1) break;
        fix[w] = 1;

        // 2. Update d[i] = min(d[i], d[w]+c[w][i])
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
    pq.push({0, st});
    while (!pq.empty()){
        int w,u,dw,v;
        tie(w,u) = pq.top(); pq.pop();
        if (d[u] != w) continue;
        for (auto nxt : adj[u]){
            tie(dw,v) = nxt;
            if (d[u]+dw < d[v]){
                d[v] = d[u]+dw;
                pq.push({d[v], v});
            }
        }
    }
}