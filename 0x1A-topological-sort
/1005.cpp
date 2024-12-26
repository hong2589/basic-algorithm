#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--){
        int cost[1001];
        int res[1001];
        int n,k;
        vector<int> adj[1001];
        int indeg[1001];
        int target;

        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> cost[i];
            res[i] = cost[i];
        }

        while (k--){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            indeg[v]++;
        }
        cin >> target;

        queue<int> q;
        for (int i = 1; i <= n; ++i){
            if (indeg[i] == 0) q.push(i);
        }
        while (!q.empty()){
            int cur = q.front(); q.pop();
            for (int nxt : adj[cur]){
                indeg[nxt]--;
                res[nxt] = max(res[nxt], res[cur]+cost[nxt]);
                if (indeg[nxt] == 0) q.push(nxt);
            }
        }

        cout << res[target] << '\n';
    }
    return 0;
}