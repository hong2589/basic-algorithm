#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    vector<int> V;
    bool zero = false;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (val == 0){
            zero = true;
            n -= 1;
        }
        else {
            V.push_back(val);
        }
    }
    sort(V.begin(), V.end());
    
    if (n == 1){
        cout << V[0] << '\n';
        return 0;
    }

    int sum1 = 0;
    int sum2 = 0;
    if (zero){
        for (int i = 1; i < n; i+=2){
            
        }
    }
    else {
        if (n % 2 == 0){
            for (int i = 0; i < n; i+=2){
                
            }
        }
    }
    
    return 0;
}