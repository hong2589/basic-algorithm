#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--){
        int n,m;
        vector<int> adj[20001];
        
        cin >> n >> m;
        while (m--){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool ans = true;
        bool vis[20001];
        int group[20001];
        fill(vis+1, vis+1+n, false);
        fill(group+1, group+1+n, -1);
        for (int i = 1; i <= n; ++i){
            if (vis[i]) continue;
            queue<int> q;
            q.push(i);
            vis[i] = true;
            group[i] = 0;
            while (!q.empty()){
                int cur = q.front();
                q.pop();
                for (int nxt : adj[cur]){
                    if (vis[nxt]){
                        if (group[nxt] == group[cur]){
                            ans = false;
                            break;
                        }
                        else {
                            continue;
                        }
                    }

                    vis[nxt] = true;
                    group[nxt] = !group[cur];
                    q.push(nxt);
                }
            }
        }

        // print answer
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
}