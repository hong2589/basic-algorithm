#include <bits/stdc++.h>
using namespace std;

int d[21][21];
int u[21][21];
vector<pair<int,int>> adj[21];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> d[i][j];
    
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            bool isAdj = true;
            for (int k = 1; k <= n; ++k){
                if (k == i || k == j) continue;
                int tmp = d[i][k] + d[k][j];
                if (tmp < d[i][j]){
                    cout << "-1\n";
                    return 0;
                }
                else if (tmp == d[i][j]){
                    isAdj = false;
                }
            }
            if (isAdj){
                u[i][j] = 1;
                u[j][i] = 1;
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n-1; ++i){
        for (int j = i+1; j <= n; ++j){
            if (u[i][j]){
                ans += d[i][j];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}