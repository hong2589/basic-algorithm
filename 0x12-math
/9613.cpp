#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (a == 0) return b;
    return gcd(b % a, a);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        int arr[105];
        vector<int> V_gcd;
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }

        for (int i = 0; i < n-1; i++){
            for (int j = i+1; j < n; j++){
                V_gcd.push_back(gcd(arr[i], arr[j]));
            }
        }
        
        long long sum = 0;
        for (vector<int>::iterator it = V_gcd.begin(); it != V_gcd.end(); it++){
            sum += *it;
        }
        cout << sum << '\n';
    }
    return 0;
}