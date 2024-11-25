#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int indeg[1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    while (m--){
        int num;
        cin >> num;
        if (num == 0) continue;
        int u = 0;
        int v;
        while (num--){
            cin >> v;
            adj[u].push_back(v);
            if (u != 0) indeg[v] += 1;
            u = v;
        }
    }

    queue<int> q;
    vector<int> result;
    for (int i = 1; i <= n; ++i){
        if (indeg[i] == 0) q.push(i);
    }

    while (!q.empty()){
        int cur = q.front();
        q.pop();
        result.push_back(cur);
        for (int nxt : adj[cur]){
            indeg[nxt] -= 1;
            if (indeg[nxt] == 0) q.push(nxt);
        }
    }

    bool isCycle = false;
    for (int i = 1; i <= n; ++i){
        if (indeg[i] != 0){
            isCycle = true;
            break;
        }
    }
    if (isCycle){
        cout << "0\n";
    }
    else {
        for (int v : result){
            cout << v << '\n';
        }
    }
    return 0;
}

    