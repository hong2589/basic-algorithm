#include <bits/stdc++.h>
using namespace std;

int dist[51][51];
vector<int> adj[51];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int u,v;
    cin >> n;
    while (cin >> u >> v){
        if (u == -1 && v == -1) break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // bfs
    for (int st = 1; st <= n; ++st){
        queue<int> q;
        fill(dist[st]+1, dist[st]+1+n, -1);
        dist[st][st] = 0;
        q.push(st);
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            for (int nxt : adj[cur]){
                if (dist[st][nxt] >= 0) continue;
                dist[st][nxt] = dist[st][cur] + 1;
                q.push(nxt);
            }
        }
    }

    vector<int> ans;
    int min_score = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i){
        int score = 0;
        bool fail = false;
        for (int j = 1; j <= n; ++j){
            if (dist[i][j] == -1){
                fail = true;
                break;
            }
            if (dist[i][j] > score){
                score = dist[i][j];
            }
        }

        if (fail) continue;
        if (score < min_score){
            ans.clear();
            min_score = score;
            ans.push_back(i);
        }
        else if (score == min_score){
            ans.push_back(i);
        }
    }
    cout << min_score << ' ' << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
    cout << '\n';

    return 0;
}