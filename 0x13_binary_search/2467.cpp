#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100000];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int a,b;
    int min = (1<<31)-1;
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            int diff = abs(arr[i]+arr[j]);
            if (diff < min){
                min = diff;
                a = arr[i];
                b = arr[j];
            }
        }
    }

    // cout << min << '\n';
    cout << a << ' ' << b << '\n';
    return 0;
}