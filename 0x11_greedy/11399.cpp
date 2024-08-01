#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int arr[1000];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += (n-i) * arr[i];
    }
    cout << sum << '\n';
    return 0;
}