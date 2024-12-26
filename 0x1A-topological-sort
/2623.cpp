#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int indeg[1001];
bool vis[1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    while (m--){
        int k;
        int u,v;
        cin >> k;
        cin >> u;
        for (int i = 0; i < k-1; ++i){
            cin >> v;
            if (find(adj[u].begin(), adj[u].end(), v) == adj[u].end()){
                adj[u].push_back(v);
                indeg[v]++;
            }
            u = v;
        }
    }


    queue<int> q;
    vector<int> ans;
    bool chk = true;
    for (int i = 1; i <= n; ++i){
        if (indeg[i] == 0) {
            q.push(i);
            vis[i] = true;
        }
    }
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for (int nxt : adj[cur]){
            if (vis[nxt]) chk = false;
            indeg[nxt]--;
            if (indeg[nxt] == 0) q.push(nxt);
        }
    }

    if (q.empty() && ans.size() != n){
        cout << "0\n";
        return 0;
    }

    if (chk){
        for (int val : ans){
            cout << val << '\n';
        }
    }
    else {
        cout << "0\n";
    }
    return 0;
}

    