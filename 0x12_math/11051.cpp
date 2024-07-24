#include <bits/stdc++.h>
using namespace std;

int mod = 10007;
long long d[1005][1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    d[1][1] = 1;
    for (int i = 1; i <= n; i++){
        d[i][0] = 1;
        d[i][i] = 1;
    }
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= i; j++){
            d[i][j] = (d[i-1][j-1] + d[i-1][j]) % mod;
        }
    }

    cout << d[n][k] << '\n';
    return 0;
}