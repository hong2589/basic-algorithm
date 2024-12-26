#include <bits/stdc++.h>
using namespace std;

int sieve(int n, int k){
    vector<bool> state(1005, true);
    state[1] = false;
    int cnt = 0;
    for (int i = 2; i <= n; i++){
        if (!state[i]) continue;
        for (int j = i; j <= n; j+=i){
            if (state[j]){
                cnt++;
                state[j] = false;
                if (cnt == k){
                    return j;
                }
            }
        }
    }
    return -1;
}

int main(){
    int n, k;
    cin >> n >> k;
    cout << sieve(n,k) << '\n';
    return 0;
}