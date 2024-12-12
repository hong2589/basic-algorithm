#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[10001]; // <w,v>
bool vis[10001];

int dfs(int u){
    int max_val = 0;
    for (auto nxt : adj[u]){
        int w,v;
        tie(w,v) = nxt;
        if (vis[v]) continue;

        int val;
        vis[v] = true;
        if (adj[v].size() == 1) val = w;
        else val = w + dfs(v);
        if (val > max_val) max_val = val;
    }
    return max_val;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n-1; ++i){
        int u,v,c;
        cin >> u >> v >> c;
        adj[u].push_back({c,v});
        adj[v].push_back({c,u});
    }

    int ans = 0;
    for (int st = 1; st <= n; ++st){
        fill(vis+1,vis+1+n,false);
        vis[st] = true;
        int res = dfs(st);
        if (res > ans) ans = res;
    }
    cout << ans << '\n';
    return 0;
}