#include <bits/stdc++.h>
using namespace std;

int arr[1000000];
int m,n;

bool Solve(int x){
    if (x == 0) return true;
    int sum = 0;
    for (int i = 0; i < n; i ++){
        sum += arr[i] / x;
    }
    return sum >= m;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int st = 0;
    int en = *max_element(arr, arr+n);
    while (st < en){
        int mid = (st+en+1)/2;
        if (Solve(mid)){
            st = mid;
        }
        else {
            en = mid-1;
        }
    }
    cout << st << '\n';
    return 0;
}