#include <bits/stdc++.h>
using namespace std;

int n,m;
int d[1001];
int pre[1001];
const int INF = 0x3f3f3f3f;
vector<pair<int,int>> adj[1001]; 

void dijkstra(int st){
    fill(d+1, d+1+n, INF);
    d[st] = 0;
    priority_queue< pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> pq;
    pq.push({0, st});
    while (!pq.empty()){
        int cur_dist, u;
        tie(cur_dist, u) = pq.top(); pq.pop();
        if (cur_dist != d[u]) continue;
        for (auto nxt : adj[u]){
            int uv_dist = nxt.first;
            int v = nxt.second;
            if (d[u] + uv_dist < d[v]){
                d[v] = d[u] + uv_dist;
                pq.push({d[v], v});
                pre[v] = u;
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

    int st, en;
    cin >> st >> en;
    dijkstra(st);

    // Answer
    stack<int> S;
    S.push(en);
    while (S.top() != st){
        S.push(pre[S.top()]);
    }
    cout << d[en] << '\n';
    cout << S.size() << '\n';
    while (!S.empty()){
        cout << S.top() << ' ';
        S.pop();
    }
    cout << '\n';
    return 0;
}