#include <bits/stdc++.h>
using namespace std;

int indeg[32001];
vector<int> adj[32001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    while (m--){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; ++i){
        if (indeg[i] == 0){
            pq.push(i);
        }
    }

    vector<int> result;
    while (!pq.empty()){
        int cur = pq.top();
        pq.pop();
        result.push_back(cur);
        for (int nxt : adj[cur]){
            indeg[nxt]--;
            if (indeg[nxt] == 0) pq.push(nxt);
        }
    }
    for (int val : result) cout << val << ' ';
    cout << '\n';
    return 0;
}