#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,r,q;
    vector<int> adj[10001];
    cin >> n >> r >> q;
    for (int i = 0; i < n-1; ++i){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    