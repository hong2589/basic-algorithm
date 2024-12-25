#include <bits/stdc++.h>
using namespace std;

const int MX = 2001;
bool isPd[MX][MX];
int n;
int arr[2001];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> arr[i];
    }
    for (int i = 1; i <= n; ++i) isPd[i][i] = true;
    for (int i = n-1; i >= 0; --i){
        for (int j = n; j >= i+1; --j){
            if (j == i+1){
                if (arr[i] == arr[j]) isPd[i][j] = true;
            }
            else {
                if (isPd[i+1][j-1] && arr[i] == arr[j]) isPd[i][j] = true;
            }
        }
    }

    int m;
    cin >> m;
    while (m--){
        int i,j;
        cin >> i >> j;
        cout << isPd[i][j] << '\n';
    }
    return 0;
}