#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int k,n;
ll arr[10000];

bool Solve(ll x){
    if (x == 0) return true;
    ll cur = 0;
    for (int i = 0; i < k; i++){
        cur += arr[i] / x;
    }
    return cur >= n;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    for (int i = 0; i < k; i++) cin >> arr[i];

    ll st = 0;
    ll en = *max_element(arr, arr+k);
    while (st < en){
        ll mid = (st+en+1)/2;
        if (Solve(mid)) st = mid;
        else en = mid-1;
    }
    cout << st << '\n';
}