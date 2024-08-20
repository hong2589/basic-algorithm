#include <bits/stdc++.h>
using namespace std;

int arr[500005];

int lower_idx(int target, int len){
    int st = 0;
    int en = len;
    while (st < en){
        int mid = (st+en)/2;
        if (arr[mid] >= target) en = mid;
        else st = mid+1;
    }
    return st;
}

int upper_idx(int target, int len){
    int st = 0;
    int en = len;
    while (st < en){
        int mid = (st+en)/2;
        if (arr[mid] <= target) st = mid+1;
        else en = mid;
    }
    return st;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    cin >> m;
    while (m--){
        int tmp;
        cin >> tmp;
        cout << upper_idx(tmp, n)-lower_idx(tmp,n) << ' ';
    }
    cout << '\n';
    return 0;
}