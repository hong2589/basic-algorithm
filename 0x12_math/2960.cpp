#include <bits/stdc++.h>
using namespace std;

vector<bool> state(1005, true);
int n, k;
int sieve(void){
    int cnt = 0;
    state[1] = false;
    for (int i = 2; i*i <= n; i++){
        if (!state[i]) continue;
        for (int j = i*i; j <= n; j += i){
            if (state[j]){
                cnt += 1;
                state[j] = false;
                if (cnt == k) return j;
            }
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    cout << sieve() << '\n';
    return 0;
}
