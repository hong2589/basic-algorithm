#include <bits/stdc++.h>
using namespace std;

int d[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int val;
        cin >> val;
        d[i] = max(d[i-1], 0) + val;
    }
    cout << *max_element(d+1, d+1+n) << '\n';
    return 0;
}