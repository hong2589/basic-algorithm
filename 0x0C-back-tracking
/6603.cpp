#include <bits/stdc++.h>
using namespace std;

int arr[15];
bool mask[15];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    while (k > 0){
        for (int i = 0; i < k; i++) cin >> arr[i];
        fill(mask, mask+k, 1);
        fill(mask, mask+6, 0);
        do {
            for (int i = 0; i < k; i++){
                if (mask[i] == 0){
                    cout << arr[i] << ' ';
                }
            }
            cout << '\n';
        } while(next_permutation(mask, mask+k));
        
        cout << '\n';
        cin >> k;
    }
    return 0;
}