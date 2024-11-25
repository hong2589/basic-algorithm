#include <bits/stdc++.h>
using namespace std;

vector<int> adj[32001];
int indeg[32001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    while (m--){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v] += 1;
    }

    queue<int> q;
    vector<int> res;
    for (int i = 1; i <= n; ++i){
        if (indeg[i] == 0) q.push(i);
    }

    while (!q.empty()){
        int cur = q.front();
        q.pop();
        res.push_back(cur);
        for (int nxt : adj[cur]){
            indeg[nxt]--;
            if (indeg[nxt] == 0) q.push(nxt);
        }
    }

    for (int v : res){
        cout << v << ' ';
    }
    cout << '\n';
    return 0;
}