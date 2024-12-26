#include <bits/stdc++.h>
using namespace std;

int mod = 1000000000;
typedef long long ll;
ll d[105][10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= 9; i++) d[1][i] = 1;

    for (int i = 2; i <= n; i++){
        for (int j = 0; j <= 9; j++){
            if (j == 0) d[i][j] = d[i-1][1];
            else if (j == 9) d[i][j] = d[i-1][8];
            else d[i][j] = d[i-1][j-1] + d[i-1][j+1];
            d[i][j] %= mod;
        }
    }

    ll sum = 0;
    for (int i = 0; i <= 9; i++){
        sum += d[n][i];
        sum %= mod;
    }
    cout << sum << '\n';
    return 0;
}
    