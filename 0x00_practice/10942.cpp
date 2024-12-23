#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    int n;
    int arr[2001];
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    int m;
    cin >> m;
    while (m--){
        int i,j;
        bool isPd = true;
        cin >> i >> j;
        while (i < j){
            if (arr[i] != arr[j]){
                isPd = false;
                break;
            }
            i++;
            j--;
        }
        cout << isPd << '\n';
    }
    return 0;
}