#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100005];

ll sumArr(ll* st, ll* en){
    ll res = 0;
    ll* it = st;
    while (it <= en){
        res += *it;
        it++;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    vector<int> V;
    ll* en = arr;
    ll sum = *arr;
    for (ll* st = arr; st != arr+n; st++){
        while (en != arr+n && sum < k) {
            en++;
            if (en != arr+n) sum += *en;
        }
        if (en == arr+n) continue;
        V.push_back(en-st+1);
        sum -= *st;
    }
    if (!V.empty()) cout << *min_element(V.begin(), V.end()) << '\n';
    else cout << "0\n";
    return 0;
}