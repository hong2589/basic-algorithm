#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int p[100001];
int vertexNum[100001];

int dfs(int cur){
    if (adj[cur].size() == 1 && p[cur] == adj[cur][0]) {
        vertexNum[cur] = 1;
        return 1;
    }

    int res = 1;
    for (int nxt : adj[cur]){
        if (p[cur] == nxt) continue;
        p[nxt] = cur;
        res += dfs(nxt);
    }
    vertexNum[cur] = res;
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,r,q;
    cin >> n >> r >> q;
    for (int i = 0; i < n-1; ++i){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(r);
    while (q--){
        int query;
        cin >> query;
        cout << vertexNum[query] << '\n';
    }
    return 0;
}
    