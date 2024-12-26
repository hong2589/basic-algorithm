#include <bits/stdc++.h>
using namespace std;

vector<int> child[100001];
int p[100001];
int praise[100001];
void dfs(int cur){
    if (p[cur] != -1){
        praise[cur] += praise[p[cur]];
    }
    for (int nxt : child[cur]){
        dfs(nxt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> p[i];
        if (p[i] == -1) continue;
        child[p[i]].push_back(i);
    }

    while (m--){
        int u,w;
        cin >> u >> w;
        praise[u] += w; 
    }

    dfs(1);
    for (int i = 1; i <= n; ++i) cout << praise[i] << ' ';
    cout << '\n';
    return 0;
}