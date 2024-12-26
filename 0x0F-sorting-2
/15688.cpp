#include <bits/stdc++.h>
using namespace std;
#define BASE 1000000

int cnt[2000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        cnt[BASE + val] += 1;
    }

    for (int i = 0; i < 2000001; i++){
        while (cnt[i] > 0){
            cout << i - BASE << '\n';
            cnt[i]--;
        }
    }
    return 0;
}