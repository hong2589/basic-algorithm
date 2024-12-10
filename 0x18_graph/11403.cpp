#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
bool vis[101];

void dfs(int cur){
    for (int nxt : adj[cur]){
        if (vis[nxt]) continue;
        vis[nxt] = true;
        dfs(nxt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int x;
            cin >> x;
            if (x == 1){
                adj[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= n; ++i){
        fill(vis+1, vis+1+n, false);
        dfs(i);
        for (int j = 1; j <= n; ++j){
            if (vis[j]) cout << "1 ";
            else cout << "0 ";
        }
        cout << '\n';
    }
    return 0;
}