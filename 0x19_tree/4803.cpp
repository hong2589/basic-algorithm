#include <bits/stdc++.h>
using namespace std;

int n,m;

bool bfs(int st, vector<int> adj[], bool vis[], int p[]){
    queue<int> q;
    q.push(st);
    vis[st] = true;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int nxt : adj[cur]){
            if (vis[nxt]){
                if (p[cur] == nxt) continue;
                else return false;
            }
            p[nxt] = cur;
            vis[nxt] = true;
            q.push(nxt);
        }
    }
    return true;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int caseNum = 1;
    while (cin >> n >> m){
        if (n == 0 && m == 0) return 0;

        vector<int> adj[501];
        bool vis[501];
        int p[501];
        fill(vis+1, vis+1+n, false);
        fill(p+1, p+1+n, 0);
        while (m--){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i){
            if (vis[i]) continue;
            if (bfs(i, adj, vis,p)) ++ans;
        }

        cout << "Case " << caseNum << ": ";
        if (ans == 0) cout << "No trees.\n";
        else if (ans == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << ans << " trees.\n";
        caseNum++;
    }
    return 0;
}