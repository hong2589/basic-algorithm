#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int n;
int BinarySearch(int target){
    int st = 0;
    int en = n-1;
    while (st <= en){
        int mid = (st+en)/2;
        if (arr[mid] < target) st = mid + 1;
        else if (arr[mid] > target) en = mid - 1;
        else return mid;
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        int t;
        cin >> t;
        int idx = BinarySearch(t);
        if (idx < 0) cout << "0\n";
        else cout << "1\n";
    }
    return 0;
}