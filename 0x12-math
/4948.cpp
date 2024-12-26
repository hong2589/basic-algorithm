#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if (n == 1) return false;
    for (int k = 2; k*k <= n; k++){
        if (n % k == 0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1){
        int n;
        cin >> n;
        if (n == 0) break;
        int cnt = 0;
        for (int k = n+1; k <= 2*n; k++){
            if (isPrime(k)) {
                // cout << k << '\n';
                cnt++; 
            }
        }       
        cout << cnt << '\n';
    }
    return 0;
}