#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll arr[5000];
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    sort(arr, arr+n);

    ll ans[3];
    ll pivot = 3'000'000'000;
    
    for (int i = 0; i < n-2; ++i){
        ll a,b,c;
        int l = i+1;
        int r = n-1;
        a = arr[i];
        while (l < r){
            b = arr[l];
            c = arr[r];
            ll tmp = a+b+c;
            if (tmp >= 0){
                if (abs(tmp) < pivot){
                    pivot = abs(tmp);
                    ans[0] = a; ans[1] = b; ans[2] = c;
                }
                r--;
            }
            else {
                if (abs(tmp) < pivot){
                    pivot = abs(tmp);
                    ans[0] = a; ans[1] = b; ans[2] = c;
                }
                l++;
            }
        }
    }
    

    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
    return 0;
}