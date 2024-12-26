#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll arr[100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    int cnt = 0;
    ll maxNum = -(111 << 62) - 1;
    int maxCnt = -1;
    for (int i = 0; i < n; i++){
        if (i == 0 || arr[i-1]==arr[i]) cnt++;
        else {
            if (cnt > maxCnt){
                maxNum = arr[i-1];
                maxCnt = cnt;
            }
            cnt = 1;
        }
    }
    if (cnt > maxCnt) maxNum = arr[n-1];

    cout << maxNum << '\n';
    return 0;
}