#include <bits/stdc++.h>
using namespace std;
int arr[500000];

int BinarySearch(int target, int len){
    int st = 0;
    int en = len-1;
    while (st <= en){
        int mid = (st+en)/2;
        if (arr[mid] > target) en = mid-1;
        else if (arr[mid] < target) st = mid+1;
        else return mid;
    }
    return -1;
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
        if (BinarySearch(tmp, n) >= 0){
            cout << 1 << ' ';
        }
        else {
            cout << 0 << ' ';
        }
    }
    cout << '\n';
    return 0;
}