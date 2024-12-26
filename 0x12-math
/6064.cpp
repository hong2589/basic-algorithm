#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (a == 0) return b;
    return gcd(b%a, a);
}

int lcm(int a, int b){
    return a / gcd(a, b) * b;
}

int solve(int n, int m, int x, int y){
    int l = lcm(n,m);
    if (x == n) x = 0;
    if (y == m) y = 0;
    // for (int k = 1; k <= l; k++){
    //     if (k % n == x && k % m == y){
    //         return k;
    //     }
    // }

    for (int k = x; k <= l; k += n){
        if (k == 0) continue;
        if (k % m == y){
            return k;
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--){
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        cout << solve(n,m,x,y) << '\n';
    }
    return 0;
}