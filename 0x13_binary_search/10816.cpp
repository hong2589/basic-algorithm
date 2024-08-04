#include <bits/stdc++.h>
using namespace std;

int arr[500005];
int n,m;

int lower_idx(int target){
    int st = 0;
    int en = n;
    while (st < en){
        int mid = (st+en)/2;
        if (arr[mid] >= target) en = mid;
        else st = mid+1;
    }
    return st;
}

int upper_idx(int target){
    int st = 0;
    int en = n;
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

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    cin >> m;
    while (m--){
        int t;
        cin >> t;
        int len = upper_idx(t) - lower_idx(t);
        cout << len << '\n';
    }
    
    return 0;
}
    