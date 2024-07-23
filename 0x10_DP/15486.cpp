#include <bits/stdc++.h>
using namespace std;

#define ARR_LEN 1500010

int T[ARR_LEN];
int P[ARR_LEN];
int d[ARR_LEN]; // d[i] : total income including a[i]

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> T[i] >> P[i];
    
    for (int i = n; i >= 1; i--){
        if (i+T[i] <= n+1) d[i] = max(d[i+1], d[i+T[i]] + P[i]);
        else d[i] = d[i+1];
    }

    cout << *max_element(d+1, d+1+n) << '\n';
    return 0;
}