#include <bits/stdc++.h>
using namespace std;

int p[51];
vector<int> adj[51];
int ans = 0;

void dfs(int cur){
    if (adj[cur].size() == 0 || (adj[cur].size() == 1 && p[adj[cur][0]] != cur)) ++ans;
    for (int nxt : adj[cur]){
        if (p[cur] == nxt) continue;
        dfs(nxt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int root;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> p[i];
        if (p[i] == -1) root = i;
    }

    int target;
    cin >> target;
    if (target == root) {
        cout << "0\n";
        return 0;
    }

    for (int i = 0; i < n; ++i){
        int u,v;
        u = i;
        v = p[i];
        if (v == -1 || u == target){
            continue;
        }

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(root);
    cout << ans << '\n';
    return 0;
}