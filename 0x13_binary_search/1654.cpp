#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int k,n;
int arr[10005];

bool solve(int x){
    int cnt = 0;
    for (int i = 0; i < k; i++) cnt += arr[i] / x;
    return cnt >= n;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;
    for (int i = 0; i < k; i++) cin >> arr[i];
    ll st = 1;
    ll en = (1<<31)-1;
    while (st < en){
        ll mid = (st+en+1)/2;
        if (solve(mid)) st = mid;
        else en = mid-1;
    }
    cout << st << '\n';
    return 0;
}