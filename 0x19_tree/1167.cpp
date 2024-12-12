#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[100001];
bool vis[100001];
int mxCost, mxNode;

void dfs(int u, int dist){
    if (dist > mxCost){
        mxCost = dist;
        mxNode = u;
    }
    for (auto [w,v] : adj[u]){
        if (vis[v]) continue;
        vis[v] = true;
        dfs(v, dist+w);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int u,v,c;
        cin >> u;
        while (cin >> v){
            if (v == -1) break;
            cin >> c;
            adj[u].push_back({c,v});
        }
    }

    
    vis[1] = true;
    dfs(1, 0);
    fill(vis+1,vis+1+n,false);
    vis[mxNode] = true;
    dfs(mxNode,0);
    
    cout << mxCost << '\n';
    return 0;
}