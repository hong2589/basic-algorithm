#include <bits/stdc++.h>
using namespace std;

priority_queue< tuple<int,int,int>,
                vector<tuple<int,int,int>>,
                greater<tuple<int,int,int>>> pq;

vector<pair<int,int>> adj[10001];
bool chk[10001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v,e;
    cin >> v >> e;
    for (int i = 0; i < e; ++i){
        int u,v,cost;
        cin >> u >> v >> cost;
        adj[u].push_back({cost,v});
        adj[v].push_back({cost,u});
    }

    long long ans = 0;
    int cnt = 0;
    chk[1] = 1;
    for (pair<int,int> nxt : adj[1]){
        pq.push({nxt.first, 1, nxt.second});
    }
    while (cnt < v-1){
        int cost,a,b;
        tie(cost,a,b) = pq.top(); pq.pop();
        if (chk[b]) continue;
        ans += cost;
        for (pair<int,int> nxt : adj[b]){
            if (!chk[nxt.second]){
                pq.push({nxt.first, b, nxt.second});
            }
        }
    }
    cout << ans << '\n';
    return 0;
}