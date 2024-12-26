#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int arr[10000];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);


    long long cnt = 0;
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            int* ub = upper_bound(arr+j+1, arr+n, -arr[i]-arr[j]);
            int* lb = lower_bound(arr+j+1, arr+n, -arr[i]-arr[j]);
            cnt += ub-lb;
        }
    }
    cout << cnt << '\n';
    return 0;
}