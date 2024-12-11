#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10001];
int cntArr[10001];
bool vis[10001];

void bfs(int st){
    queue<int> q;
    q.push(st);
    vis[st] = true;
    cntArr[st] = 1;
    while (!q.empty()){
        int cur = q.front(); q.pop();
        cntArr[st]++;
        for (int nxt : adj[cur]){
            if (vis[nxt]) continue;
            vis[nxt] = true;
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
        adj[v].push_back(u);
    }

    for (int st = 1; st <= n; ++st){
        fill(vis+1, vis+1+n, false);
        bfs(st);
    }

    vector<int> ans;
    int cmp = 0;
    for (int i = 1; i <= n; ++i){
        if (cntArr[i] > cmp){
            cmp = cntArr[i];
            ans.clear();
            ans.push_back(i);
        }
        else if (cntArr[i] == cmp){
            ans.push_back(i);
        }
    }
    for (int x : ans) cout << x << ' ';
    cout << '\n';
    return 0;
}