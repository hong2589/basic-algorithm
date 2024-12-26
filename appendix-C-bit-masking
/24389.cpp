#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned int n;
    unsigned int m;
    cin >> n;
    m = ~n+1;

    unsigned int res = n ^ m;
    int ans = 0;
    for (int i = 0; i < 32; ++i){
        ans += ((res>>i) & 1);
    }
    cout << ans << '\n';
    return 0;
}

    