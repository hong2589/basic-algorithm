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
        indeg[v]++;
    }


    queue<int> q;
    for (int i = 1; i <= n; ++i){
        if (indeg[i] == 0){
            q.push(i);
        }
    }

    while (!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (int nxt : adj[cur]){
            indeg[nxt]--;
            if (indeg[nxt] == 0) q.push(nxt);
        }
    }
    cout << '\n';
    
    return 0;
}