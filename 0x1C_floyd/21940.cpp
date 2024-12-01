#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[201][201];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) fill(d[i]+1, d[i]+1+n, INF);
    for (int i = 1; i <= n; ++i) d[i][i] = 0;
    while (m--){
        int a,b,c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }

    int t;
    vector<int> addr;
    cin >> t;
    for (int i = 0; i < t; ++i){
        int x;
        cin >> x;
        addr.push_back(x);
    }

    for (int k = 1; k <= n; ++k){
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                if (d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    // // show d[i][j]
    // for (int i = 1; i <= n; ++i){
    //     for (int j = 1; j <= n; ++j){
    //         if (d[i][j] == INF) cout << "-1 ";
    //         else cout << d[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    vector<int> ans;
    int mini = INF;
    for (int k = 1; k <= n; ++k){
        bool isCont = false;
        int max_dist = 0;
        for (int st : addr){
            if (d[st][k] == INF || d[k][st] == INF){
                isCont = true;
                break;
            }
            if (d[st][k] + d[k][st] > max_dist) max_dist = d[st][k] + d[k][st];
        }
        if (isCont) continue;
        if (max_dist > mini) continue;
        if (max_dist < mini){
            mini = max_dist;
            ans.clear();
        }
        ans.push_back(k);
    }
    for (int x : ans) cout << x << ' ';
    cout << '\n';
    return 0;
}