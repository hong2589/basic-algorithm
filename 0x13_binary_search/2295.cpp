#include <bits/stdc++.h>
using namespace std;

vector<int> two;

int BinarySearch(int target, int len){
    int st = 0;
    int en = len-1;
    while (st <= en){
        int mid = (st+en)/2;
        if (two[mid] > target) en = mid-1;
        else if (two[mid] < target) st = mid+1;
        else return mid;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int arr[1005];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            two.push_back(arr[i]+arr[j]);
        }
    }
    sort(two.begin(), two.end());

    for (int i = n-1; i >= 0; i--){
        for (int j = 0; j < n; j++){
            // if (BinarySearch(arr[i]-arr[j], n) >= 0){
            //     cout << arr[i] << '\n';
            //     return 0;
            // }
            if (binary_search(two.begin(), two.end(), arr[i]-arr[j])){
                cout << arr[i] << '\n';
                return 0;
            }
        }
    }
    return 0;
}