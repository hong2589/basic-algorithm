#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int u, v;
    vector<int> adj[51];
    cin >> n;
    cin >> u >> v;
    while (u > 0 && v > 0){
        adj[u].push_back(v);
        adj[v].push_back(u);
        cin >> u >> v;
    }

    int nomidate[51];
    for (int i = 1; i <= n; ++i){
        int dist[51];
        int max_val = 0;
        fill(dist+1, dist+n+1, -1);
        queue<int> q;
        q.push(i);
        dist[i] = 0;
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            if (dist[cur] > max_val) max_val = dist[cur];
            for (int nxt : adj[cur]){
                if (dist[nxt] >= 0) continue;
                q.push(nxt);
                dist[nxt] = dist[cur] + 1;
            }
        }
        nomidate[i] = max_val;
    }

    // for (int i = 1; i <= n; ++i) cout << nomidate[i] << ' ';
    // cout << '\n';

    int min = 100;
    vector<int> ans;
    for (int i = 1; i <= n; ++i){
        if (nomidate[i] > min) continue;
        if (nomidate[i] < min) {
            ans.clear();
            min = nomidate[i];
        }
        ans.push_back(i);
    }

    cout << min << ' ' << ans.size() << '\n';
    for (auto ent : ans) cout << ent << ' ';
    cout << '\n';
    return 0;
}