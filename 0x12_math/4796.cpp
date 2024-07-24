#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (1){
        int l, p, v;
        cin >> l >> p >> v;
        if (l == 0 && p == 0 && v == 0) break;
        
        int q = v / p;
        int r = v % p;
        int res = l * q + min(l, r);
        cout << "Case " << t << ": " << res << '\n';
        t++;
    }
    return 0;
}