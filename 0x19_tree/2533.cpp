#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000001];
int level[1000001];

void bfs(int st){
    queue<int> q;
    q.push(st);
    level[st] = 1;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int nxt : adj[cur]){
            if (level[nxt] > 0) continue;
            level[nxt] = level[cur] + 1;
            q.push(nxt);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n-1; ++i){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i){
        int levelCnt[1000001] = {};
        fill(level+1, level+1+n, 0);
        bfs(i);
        for (int j = 1; j <= n; ++j){
            levelCnt[level[j]]++;
        }

        int size = *max_element(level+1, level+1+n);
        int cur = 1;
        int cnt = 0;
        while (cur <= size-1){
            if (levelCnt[cur] < levelCnt[cur+1]) {
                cnt += levelCnt[cur];
                cur += 1;
            }
            else {
                cnt += levelCnt[cur+1];
                cur += 2;
            }
        }
        if (cnt < ans) ans = cnt;
    }
    cout << ans << '\n';
    return 0;
}