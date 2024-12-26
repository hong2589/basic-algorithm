#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
int dist[101][101];
int k_num[101];

void bfs(int st){
    queue<int> q;
    q.push(st);
    dist[st][st] = 0;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int nxt : adj[cur]){
            if (dist[st][nxt] >= 0) continue;
            dist[st][nxt] = dist[st][cur]+1;
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

    for (int i = 1; i <= n; ++i){
        fill(dist[i]+1, dist[i]+1+n, -1);
        bfs(i);
        for (int j = 1; j <= n; ++j){
            k_num[i] += dist[i][j];
        }
    }

    int ans;
    int min_val = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i){
        if (k_num[i] < min_val){
            ans = i;
            min_val = k_num[i];
        }
    }
    cout << ans << '\n';
    return 0;
}