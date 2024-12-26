#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    int n;
    ll arr[100001];
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int i = 0;
    int j = n-1;
    ll a = arr[0];
    ll b = arr[n-1];
    while (i < j){
        ll tmp = arr[i]+arr[j];
        if (tmp > 0){
            if (abs(tmp) < abs(a+b)){
                a = arr[i];
                b = arr[j];
            }
            j--;
        }
        else if (tmp < 0){
            if (abs(tmp) < abs(a+b)){
                a = arr[i];
                b = arr[j];
            }
            i++;
        }
        else {
            a = arr[i];
            b = arr[j];
            break;
        }
    }
    cout << a << ' ' << b << '\n';
    return 0;
}