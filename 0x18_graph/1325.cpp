#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10002];

int bfs(int st, int n){
    queue<int> q;
    bool vis[10002];
    int cnt = 0;
    fill(vis+1, vis+n+1, 0);
    vis[st] = 1;
    q.push(st);
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        cnt += 1;
        for (int nxt : adj[cur]){
            if (vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    while (m--){
        int u,v;
        cin >> u >> v;
        adj[v].push_back(u);
    }

    int max = 0;
    vector<int> ans;
    for (int i = 1; i <= n; ++i){
        int cnt = bfs(i, n);
        if (cnt > max){
            max = cnt;
            ans.clear();
            ans.push_back(i);
        }
        else if (cnt == max){
            ans.push_back(i);
        }
    }

    for (auto x : ans) cout << x << ' ';
    cout << '\n';
    return 0;
}