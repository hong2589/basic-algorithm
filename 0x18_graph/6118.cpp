#include <bits/stdc++.h>
using namespace std;

int dist[20001];
vector<int> adj[20001];

void bfs(int st){
    queue<int> q;
    q.push(st);
    dist[st] = 0;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int nxt : adj[cur]){
            if (dist[nxt] >= 0) continue;
            dist[nxt] = dist[cur]+1;
            q.push(nxt);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    while (m--){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(dist+1, dist+1+n, -1);
    bfs(1);

    vector<int> ans;
    int max_dist = 0;
    for (int i = 1; i <= n; ++i){
        if (dist[i] > max_dist){
            ans.clear();
            ans.push_back(i);
            max_dist = dist[i];
        }
        else if (dist[i] == max_dist){
            ans.push_back(i);
        }
    }

    cout << ans[0] << ' ' << max_dist << ' ' << ans.size() << '\n';
    return 0;
}