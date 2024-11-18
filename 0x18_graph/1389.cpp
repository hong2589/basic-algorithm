#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    vector<int> adj[101];
    cin >> n >> m;
    while (m--){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int kv_num[101];
    for (int i = 1; i <= n; ++i){
        int dist[101];
        queue<int> q;
        fill(dist+1, dist+n+1, -1);
        dist[i] = 0;
        q.push(i);
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            for (int nxt : adj[cur]){
                if (dist[nxt] >= 0) continue;
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }

        int num = 0;
        for (int j = 1; j <= n; ++j){
            if (dist[j] > 0) num += dist[j];
        }
        kv_num[i] = num;
    }

    // find min, idx
    int min = 1<<30;
    int idx;
    for (int i = 1; i <= n; ++i){
        // cout << kv_num[i] << ' ';
        if (kv_num[i] >= min) continue;
        min = kv_num[i];
        idx = i;
    }
    cout << idx << '\n';
    return 0;
}