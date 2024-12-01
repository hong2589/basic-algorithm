#include <bits/stdc++.h>
using namespace std;

int n,m,x;
int d[1005][1005];
vector<pair<int,int>> adj[1005];
const int INF = 0x3f3f3f3f;

void dijkstra(int st){
    fill(d[st]+1, d[st]+1+n, INF);
    d[st][st] = 0;

    priority_queue< pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> pq;
    pq.push({0, st});
    while (!pq.empty()){
        int u,w,dw,v;
        tie(w,u) = pq.top(); pq.pop();
        if (d[st][u] != w) continue;
        for (auto nxt : adj[u]){
            tie(dw,v) = nxt;
            if (d[st][u]+dw < d[st][v]){
                d[st][v] = w+dw;
                pq.push({d[st][v], v});
            }
        }
    }
}

void show(){
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x;
    while (m--){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
    }

    for (int i = 1; i <= n; ++i){
        dijkstra(i);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i){
        if (d[i][x] + d[x][i] > ans) ans = d[i][x] + d[x][i];
    }

    cout << ans << '\n';
    return 0;
}   