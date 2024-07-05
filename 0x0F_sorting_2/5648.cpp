#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll arr[1000000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++){
        string str;
        cin >> str;
        reverse(str.begin(), str.end());
        arr[i] = stoll(str);
    }
    sort(arr, arr+n);
    for (int i = 0; i < n; i++) cout << arr[i] << '\n';
    return 0;
}