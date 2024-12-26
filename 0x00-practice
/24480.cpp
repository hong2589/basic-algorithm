#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
bool vis[100001];
int order[100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,r;
    cin >> n >> m >> r;
    while (m--){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i){
        sort(adj[i].begin(), adj[i].end());
    }

    stack<int> s;
    int cnt = 0;
    s.push(r);
    while (!s.empty()){
        int cur = s.top();
        s.pop();
        if (vis[cur]) continue;
        order[cur] = ++cnt;
        vis[cur] = true;
        for (int nxt : adj[cur]){
            if (vis[nxt]) continue;
            s.push(nxt);
        }
    }

    for (int i = 1; i <= n; ++i){
        cout << order[i] << '\n';
    }
    return 0;
}