#include <bits/stdc++.h>
using namespace std;

#define STATE_LEN 2000000001
#define OFFSET 1000000000
bool state[STATE_LEN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int arr[2000];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    int cnt = 0;
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            int target = arr[i] + arr[j];
            int* ub = upper_bound(arr+j+1, arr+n, target);
            int* lb = lower_bound(arr+j+1, arr+n, target);
            if (!state[target+OFFSET]){
                cnt += ub-lb;
                state[target+OFFSET] = true;
            }
            // cout << arr[i] << ' ' << arr[j] << ' ' << cnt << ' ' << '\n';
        }
    }

    cout << cnt << '\n';
    return 0;
}