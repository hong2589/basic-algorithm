#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b){
    return a > b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a[55];
    int b[55];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(b, b+n); // sort by ascending order
    sort(a, a+n, comp); // sort by descending order
    int s = 0;
    for (int i = 0; i < n; i++){
        s += b[i] * a[i];
    }
    cout << s << '\n';
    return 0;
}