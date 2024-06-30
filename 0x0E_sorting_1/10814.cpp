#include <bits/stdc++.h>
using namespace std;

pair<int, string> arr[100001];

bool compare(pair<int, string> p1, pair<int, string> p2){
    return p1.first < p2.first;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int val;
        string str;
        cin >> val >> str;
        arr[i] = {val, str};
    }
    stable_sort(arr, arr+n, compare);
    for (int i = 0; i < n; i++){
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }
    return 0;
}