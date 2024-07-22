#include <bits/stdc++.h>
using namespace std;

int d[100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    
    
    cin >> n >> m;
    d[0] = 0;
    for (int i = 1; i <= n; i++){
        int val;
        cin >> val;
        d[i] = d[i-1] + val;
    }

    while (m--){
        int i, j;
        cin >> i >> j;
        cout << d[j] - d[i-1] << '\n';
    }
    
    return 0;
}