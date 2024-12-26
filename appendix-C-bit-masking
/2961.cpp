#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<pair<ll,ll>> arr;
unsigned ll INF = 0x7FFFFFFFFFFFFFFF;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        ll a,b;
        cin >> a >> b;
        arr.push_back({a,b});
    }
    
    ll ans = INF;
    for (int i = 1; i <= n; ++i){
        // i: # of selected ingredients
        vector<int> mask(n-i, 0);
        for (int j = 0; j < i; ++j) mask.push_back(1);
        do {
            ll a = 1;
            ll b = 0;
            for (int j = 0; j < n; ++j){
                if (mask[j] == 1){
                    a *= arr[j].first;
                    b += arr[j].second;
                }
            }
            if (abs(a-b) < ans) ans = abs(a-b);
        } while(next_permutation(mask.begin(), mask.end()));
    }
    cout << ans << '\n';
    return 0;
}