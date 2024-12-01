#include <bits/stdc++.h>
using namespace std;

int item[101];
int d[101][101];
const int INF = 0x3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,r;
    cin >> n >> m >> r;
    for (int i = 1; i <= n; ++i) cin >> item[i];
    for (int i = 1; i <= n; ++i) fill(d[i]+1, d[i]+1+n, INF);
    for (int i = 1; i <= n; ++i) d[i][i] = 0;
    while (r--){
        int a,b,c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
        d[b][a] = min(d[b][a], c);
    }

    // Floyd Algorithm
    for (int k = 1; k <= n; ++k){
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; ++i){
        int sum = item[i];
        for (int j = 1; j <= n; ++j){
            if (d[i][j] > 0 && d[i][j] <= m){
                sum += item[j];
            }
        }
        if (sum > res) res = sum;
    }
    cout << res << '\n';
    return 0;
}