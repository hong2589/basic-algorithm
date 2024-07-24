#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    for (int k = 2; k*k <= n; k++){
        while (n % k == 0){
            cout << k << '\n';
            n /= k;
        }
    }
    if (n != 1) cout << n << '\n';
    return 0;
}