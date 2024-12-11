#include <bits/stdc++.h>
using namespace std;

vector<int> adj1[101]; // W->w
vector<int> adj2[101]; // w->W
int arr1[101];
int arr2[101];
int n,m;

void bfs1(int st){
    queue<int> q;
    bool vis[101];
    fill(vis+1, vis+1+n, false);

    q.push(st);
    vis[st] = true;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int nxt : adj1[cur]){
            if (vis[nxt]) continue;
            vis[nxt] = true;
            q.push(nxt);
            arr1[st]++;
        }
    }
}

void bfs2(int st){
    queue<int> q;
    bool vis[101];
    fill(vis+1, vis+1+n, false);

    q.push(st);
    vis[st] = true;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int nxt : adj2[cur]){
            if (vis[nxt]) continue;
            vis[nxt] = true;
            q.push(nxt);
            arr2[st]++;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while (m--){
        int u,v;
        cin >> u >> v;
        adj1[u].push_back(v);
        adj2[v].push_back(u);
    }

    int target = (n+1)/2;
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        bfs1(i);
        bfs2(i);
        if (arr1[i] >= target || arr2[i] >= target) ans++;
    }
    cout << ans << '\n';
    return 0;
}