#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int p[100001];
int vertex_num[100001];

void dfs(int cur){
    for (int nxt : adj[cur]){
        if (nxt == p[cur]) continue;
        p[nxt] = cur;
        dfs(nxt);
    }
}

void countVertex(int cur){
    int cnt = 1;
    for (int nxt : adj[cur]){
        if (nxt == p[cur]){
            if (adj[cur].size() == 1){
                // leaf
                vertex_num[nxt] = 1;
            }
            continue;
        }
        countVertex(nxt);
        cnt += vertex_num[nxt];
    }
    vertex_num[cur] = cnt;
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
    countVertex(r);

    while (q--){
        int root;
        cin >> root;
        cout << vertex_num[root] << '\n';
    }
    return 0;
}
    