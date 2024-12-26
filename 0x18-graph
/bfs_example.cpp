#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10];
bool vis[10];

void bfs(){
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cut << ' ';
        for (auto v : adj[cur]){
            if (vis[v]) continue;
            q.push(v);
            vis[v] = true;
        }
    }
}