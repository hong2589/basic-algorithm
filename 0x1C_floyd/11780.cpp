#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[101][101];
int nxt[101][101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        fill(d[i]+1, d[i]+1+n, INF);
    }
    for (int i = 1; i <= n; ++i) d[i][i] = 0;
    while (m--){
        int u,v,c;
        cin >> u >> v >> c;
        if (c < d[u][v]) {
            d[u][v] = c;
            nxt[u][v] = v;
        }
    }

    for (int k = 1; k <= n; ++k){
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                if (d[i][k]+d[k][j] < d[i][j]){
                    d[i][j] = d[i][k]+d[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (d[i][j] == INF) d[i][j] = 0;
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }

    // path tracing
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (d[i][j] == 0 || d[i][j] == INF){
                cout << "0\n";
                continue;
            }

            vector<int> path;
            int st = i;
            while (st != j){
                path.push_back(st);
                st = nxt[st][j];
            }
            path.push_back(j);
            cout << path.size() << ' ';
            for (int p : path) cout << p << ' ';
            cout << '\n';
        }
    }
    return 0;
}