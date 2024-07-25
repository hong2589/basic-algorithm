#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    int arr[100005];
    vector<int> V_diff;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    
    int* st = arr;
    int* en = arr;
    while (st != arr+n && en != arr+n){
        int diff = abs(*st-*en);
        if (diff < m) en++;
        else {
            V_diff.push_back(diff);
            st++;
        }
    }

    cout << *min_element(V_diff.begin(), V_diff.end()) << '\n';
    return 0;
}