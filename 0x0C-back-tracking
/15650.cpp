#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isused[10];

void func(int k){
    if (k == m){
        for (int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int st = (k == 0)? 0 : arr[k-1];
    for (int i = st; i < n; i++){
        if (!isused[i]){
            arr[k] = i+1;
            isused[i] = 1;
            func(k+1);
            isused[i] = 0;
        }
    }
}

int main(){
    cin >> n >> m;

    // bool a[10];
    // fill(a, a+n, 1);
    // fill(a, a+m, 0);
    // do {
    //     for (int i = 0; i < n; i++){
    //         if (a[i] == 0) cout << i+1 << ' ';
    //     }
    //     cout << '\n';
    // } while (next_permutation(a, a+n));
    func(0);
    return 0;
}