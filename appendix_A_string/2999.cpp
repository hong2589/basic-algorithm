#include <bits/stdc++.h>
using namespace std;
char arr[105][105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int n;
    cin >> s;
    n = s.size();

    int r,c;
    for (int i = 1; i*i <= n; ++i){
        if (n % i == 0) r = i;
    }
    c = n / r;

    int pos = 0;
    for (int j = 0; j < c; ++j){
        for (int i = 0; i < r; ++i){
            arr[i][j] = s[pos++];
        }
    }

    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            cout << arr[i][j];
        }
    }
    cout << '\n';
    return 0;
}