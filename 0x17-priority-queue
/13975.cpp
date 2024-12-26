#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--){
        int k;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        cin >> k;
        for (int i = 0; i < k; ++i){
            int x;
            cin >> x;
            pq.push(x);
        }

        ll ans = 0;
        while (pq.size() > 1){
            ll a = pq.top(); pq.pop();
            ll b = pq.top(); pq.pop();
            ll c = a + b;
            pq.push(c);
            ans += c;
        }

        cout << ans << '\n';
    }
    return 0;
}