#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;

ll arr[1000000];

bool Solve(ll x){
    if (x == 0) return true;
    ll sum = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] <= x) continue;
        sum += arr[i]-x;
    }
    return sum >= m;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    ll st = 0;
    ll en = *max_element(arr, arr+n);
    while (st < en){
        ll mid = (st+en+1)/2;
        if (Solve(mid)) st = mid;
        else en = mid-1;
    }
    cout << st << '\n';
    return 0;
}