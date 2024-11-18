#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
bool vis1[1001];
bool vis2[1001];

bool comp(int a, int b){
    return a > b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, st;
    cin >> n >> m >> st;
    while (m--){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int i = 1; i <= n; ++i){
        sort(adj[i].begin(), adj[i].end(), comp);
    }
    stack<int> s;
    s.push(st);
    while (!s.empty()){
        int cur = s.top();
        s.pop();
        if (vis1[cur]) continue;
        cout << cur << ' ';
        vis1[cur] = true;
        for (int nxt : adj[cur]){
            if (vis1[nxt]) continue;
            s.push(nxt);
        }
    }
    cout << '\n';

    for (int i = 1; i <= n; ++i){
        sort(adj[i].begin(), adj[i].end());
    }
    queue<int> q;
    q.push(st);
    vis2[st] = true;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (int nxt : adj[cur]){
            if (vis2[nxt]) continue;
            vis2[nxt] = true;
            q.push(nxt);
        }
    }
    cout << '\n';
    return 0;
}