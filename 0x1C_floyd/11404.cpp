#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[101][101];

int main(){
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        fill(d[i]+1, d[i]+1+n, INF);
    }
    for (int i = 1; i <= n; ++i){
        d[i][i] = 0;
    }

    while (m--){
        int u,v,c;
        cin >> u >> v >> c;
        d[u][v] = min(d[u][v], c);
    }
    

    for (int k = 1; k <= n; ++k){
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (d[i][j] == INF) cout << "0 ";
            else cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;

}