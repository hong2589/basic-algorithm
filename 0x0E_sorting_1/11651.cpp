#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    if (p1.second != p2.second) return p1.second < p2.second;
    return p1.first < p2.first;
}

int main(){
    int n;
    cin >> n;
    pair<int, int> arr[100000];
    for (int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr+n, compare);
    for (int i = 0; i < n; i++){
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }
    return 0;
}