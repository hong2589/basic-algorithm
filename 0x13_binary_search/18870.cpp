#include <bits/stdc++.h>
using namespace std;
int lowerIdx(int sortedArr[], int n, int target){
    int st = 0;
    int en = n;
    while (st < en){
        int mid = (st+en)/2;
        if (sortedArr[mid] < target) st = mid+1;
        else if (sortedArr[mid] >= target) en = mid;
    }
    return st;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[1000000];
    int sortedArr[1000000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        arr[i] = t;
        sortedArr[i] = t;
    }
    sort(sortedArr, sortedArr+n);
    
    for (int i = 0; i < n; i++){
        cout << lowerIdx(sortedArr, n, arr[i]) << ' ';
    }
    return 0;
}