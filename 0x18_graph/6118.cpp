#include <bits/stdc++.h>
using namespace std;

vector<int> graph[20001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    while (m--){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int dist[20001];
    queue<int> q;
    fill(dist+1, dist+n+1, -1);
    dist[1] = 0;
    q.push(1);
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int nxt : graph[cur]){
            if (dist[nxt] >= 0) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }

    int cnt = 0;
    int idx;
    int max = 0;
    for (int i = 1; i <= n; ++i){
        if (dist[i] > max){
            max = dist[i];
            cnt = 1;
            idx = i;
        }
        else if (dist[i] == max){
            cnt += 1;
        }
    }
    cout << idx << ' ' << dist[idx] << ' ' << cnt << '\n';
    return 0;
}