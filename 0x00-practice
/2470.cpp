#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll arr[100'000];
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    sort(arr, arr+n);

    ll cmp = 2'000'000'000;
    int l = 0;
    int r = n-1;
    pair<ll,ll> ans;
    while (l < r){
        ll a = arr[l];
        ll b = arr[r];
        ll tmp;
        if (a >= 0 && b >= 0){
            r = l+1;
            b = arr[r];
            tmp = abs(a+b);
            if (tmp < cmp) {
                cmp = tmp;
                ans = {a,b};
            }
            break;
        }
        else if (a < 0 && b < 0){
            l = r-1;
            a = arr[l];
            tmp = abs(a+b);
            if (tmp < cmp) {
                cmp = tmp;
                ans = {a,b};
            }
            break;
        }

        if (a+b == 0){
            ans = {a,b};
            break;
        }

        if (a+b < 0){
            if (abs(a+b) < cmp) {
                cmp = abs(a+b);
                ans = {a,b};
            }
            l++;
        }
        else {
            if (abs(a+b) < cmp) {
                cmp = abs(a+b);
                ans = {a,b};
            }
            r--;
        }
    }

    cout << ans.first << ' ' << ans.second << '\n';
    return 0;
}