#include <bits/stdc++.h>
using namespace std;

int indeg[101];
int part[101][101];
vector<int> adj[101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m; 
    cin >> n >> m;
    while (m--){
        int v,u,num;
        cin >> v >> u >> num;
        adj[u].push_back(v);
        indeg[v]++;
        part[v][u] = num;
    }

    queue<int> q;
    vector<int> base;
    for (int i = 1; i <= n; ++i){
        if (indeg[i] == 0){
            q.push(i);
            base.push_back(i);
        }
    }
    while (!q.empty()){
        int cur = q.front(); q.pop();
        for (int nxt : adj[cur]){
            indeg[nxt]--;
            if (indeg[nxt] == 0) q.push(nxt);
            
            int mul = part[nxt][cur];
            for (int b : base){
                part[nxt][b] += mul * part[cur][b];
            }
        }
    }
    for (int b : base){
        cout << b << ' ' << part[n][b] << '\n';
    }
    return 0;
}