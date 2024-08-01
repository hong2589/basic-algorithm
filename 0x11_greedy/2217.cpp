#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int arr[100005];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    
    long long max = 0;
    for (int i = 0; i < n; i++){
        long long val = (i+1) * arr[n-1-i];
        if (val > max) max = val;
    }
    cout << max << '\n';
    return 0;
}

    

