#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll d[101] = {0, 1, 1, 1, 2, 2};
    for (int i = 6; i <= 100; i++){
        d[i] = d[i-1] + d[i-5];
    }
    
    int T;
    cin >> T;
    while (T--){
        int N;
        cin >> N;
        cout << d[N] << '\n';
    }
    
    return 0;
}