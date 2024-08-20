#include <bits/stdc++.h>
using namespace std;

vector<int> tmp, uniq;
int arr[1000000];

int lower_idx(int target, int len){
    int st = 0;
    int en = len;
    while (st < en){
        int mid = (st+en)/2;
        if (uniq[mid] >= target) en = mid;
        else st = mid+1;
    }
    return st;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        tmp.push_back(arr[i]);
    }

    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < n; i++){
        if (i == 0 || tmp[i] != tmp[i-1]){
            uniq.push_back(tmp[i]);
        }
    }

    for (int i = 0; i < n; i++){
        cout << lower_idx(arr[i], uniq.size()) << ' ';
    }
    cout << '\n';
    return 0;
}