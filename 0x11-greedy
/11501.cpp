#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--){
        int n;
        int price[1000001];
        cin >> n;
        for (int i = 0; i < n; i++) cin >> price[i];
        
        int max = price[n-1];
        long long sum = 0;
        for (int i = n-1; i >= 0; i--){
            if (price[i] > max){
                max = price[i];
            }
            else {
                sum += max - price[i];
            }
        }
        cout << sum << '\n';
    }
    return 0;
}