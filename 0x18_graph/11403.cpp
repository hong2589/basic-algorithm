#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
bool ans[101][101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int val;
            cin >> val;
            if (val==1) adj[i].push_back(j);
        }
    }
    
    for (int i = 1; i <= n; ++i){
        queue<int> q;
        bool vis[101];
        fill(vis+1, vis+n+1, 0);
        q.push(i);
        vis[i] = true;
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            for (int nxt : adj[cur]){
                if (nxt == i) ans[i][i] = true;
                if (vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
        for (int j = 1; j <= n; ++j){
            if (vis[j] && j != i) ans[i][j] = true;
        }
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cout << ((ans[i][j])? 1 : 0) << ' ';
        }
        cout << '\n';
    }
    return 0;
}