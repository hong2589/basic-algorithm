#include <bits/stdc++.h>
using namespace std;

bool IsPrime(int val){
    if (val == 1) return 0;
    for (int k = 2; k*k <= val; k++){
        if (val % k == 0) return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        if (IsPrime(val)) sum += 1;
    }
    cout << sum << '\n';
    return 0;
}