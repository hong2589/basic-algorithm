#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> arr; // <name, mask(bit)>
int n,m;

ll cvt2mask(string& s){
    ll res = 0;
    for (int i = 0; i < s.size(); ++i){
        if (s[i] == 'Y') res |= ((ll)1<<i);
    }
    return res;
}

int findOnes(ll x){
    int res = 0;
    for (int i = 0; i < m; ++i){
        res += ((x >> i) & 1);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    for (int i = 0; i < n; ++i){
        string name, mask_str;
        cin >> name >> mask_str;
        arr.push_back(cvt2mask(mask_str));
    }

    // for (ll x : arr) cout << x << ' ';
    // cout << '\n';

    int num_guitar = 0;
    int num_song = 0;
    for (int i = 1; i <= n; ++i){
        // i : # of selected guitars
        vector<int> sel_guitar;
        for (int j = 0; j < n-i; ++j) sel_guitar.push_back(0);
        for (int j = 0; j < i; ++j) sel_guitar.push_back(1);
        do {
            ll tmp = 0;
            for (int j = 0; j < n; ++j){
                if (sel_guitar[j] == 1){
                    tmp |= arr[j];
                }
            }
            if (findOnes(tmp) > num_song){
                num_song = findOnes(tmp);
                num_guitar = i;
            }

        } while (next_permutation(sel_guitar.begin(), sel_guitar.end()));
    }

    // cout << num_song << '\n';
    if (num_song == 0) cout << "-1\n";
    else cout << num_guitar << '\n';
    return 0;
}