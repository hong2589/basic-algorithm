#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101005];
int dist[101005];
void bfs(int st){
    queue<int> q;
    q.push(st);
    dist[st] = 0;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int nxt : adj[cur]){
            if (dist[nxt] > 0) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k,m;
    cin >> n >> k >> m;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= k; ++j){
            int x;
            cin >> x;
            adj[n+i].push_back(x);
            adj[x].push_back(n+i);
        }
    }

    bfs(1);
    if (n == 1){
        cout << "1\n";
        return 0;
    }
    if (dist[n] == 0) cout << "-1\n";
    else cout << dist[n]/2+1 << '\n';
    return 0;
}