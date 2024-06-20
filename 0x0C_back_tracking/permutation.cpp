#include <bits/stdc++.h>
using namespace std;

int main(){
    // 1. Permutation example
    cout << "===== 1. Permutation =====\n";
    int a[4] = {1,2,3,4};
    do {
        for (int i = 0; i < 4; i++){
            cout << a[i];
        }
        cout << '\n';
    } while (next_permutation(a, a+4));

    // 2. Permutation example
    cout << '\n';
    cout << "===== 2. Combination =====\n";
    sort(a, a+4);
    int b[4] = {0,0,1,1}; // 4C2
    do {
        for (int i = 0; i < 4; i++){
            if (b[i] == 0) cout << a[i];
        }
        cout << '\n';
    } while (next_permutation(b, b+4));
    return 0;
}