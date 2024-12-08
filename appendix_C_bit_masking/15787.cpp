#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<int> arr(n+1,0);
    while (m--){
        int inst;
        int i, x;
        cin >> inst;
        if (inst == 1){
            cin >> i >> x;
            arr[i] |= (1<<x);
        }
        else if (inst == 2){
            cin >> i >> x;
            arr[i] &= (~(1<<x));
        }
        else if (inst == 3){
            cin >> i;
            arr[i] = arr[i] << 1;
            arr[i] = arr[i] & ((1<<21)-1);
        }
        else if (inst == 4){
            cin >> i;
            arr[i] = arr[i] >> 1;
            arr[i] &= ~1;
        }
    }

    vector<int> record;
    int ans = 0;

    for (int i = 1; i <= n; ++i){
        if (find(record.begin(), record.end(), arr[i]) == record.end()){
            record.push_back(arr[i]);
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}