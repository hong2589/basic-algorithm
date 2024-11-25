#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> adj[10];
    int indeg[10];
    int n;

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
            if (indeg[nxt] == 0){
                q.push(nxt);
            }
        }
    }
}