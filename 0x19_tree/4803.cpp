#include <bits/stdc++.h>
using namespace std;

bool IsTree(vector<int> adj[], int parent[], int st){
    if (parent[st] != -1) return false;
    
    bool res = true;
    queue<int> q;
    q.push(st);
    parent[st] = 0; // root node
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int nxt : adj[cur]){
            if (parent[nxt] != -1){
                if (nxt != parent[cur]) res = false;
                continue;
            }
            q.push(nxt);
            parent[nxt] = cur;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    int caseCnt = 0;
    cin >> n >> m;
    while (n > 0 || m > 0){
        vector<int> adj[501];
        while(m--){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int treeCnt = 0;
        int parent[501];
        fill(parent+1, parent+1+n, -1);
        for (int st = 1; st <= n; ++st){
            if (IsTree(adj, parent, st)){
                treeCnt += 1;
            }
        }
        
        cout << "Case " << ++caseCnt << ": ";
        if (treeCnt == 0){
            cout << "No trees.\n";
        }
        else if (treeCnt == 1){
            cout << "There is one tree.\n";
        }
        else {
            cout << "A forest of " << treeCnt << " trees.\n";
        }
        cin >> n >> m;
    }
    return 0;
}