#include <bits/stdc++.h>
using namespace std;

vector<int> divisor(int n){
    vector<int> div;
    for (int k = 1; k*k <= n; k++){
        if (n % k == 0) div.push_back(k);
    }
    for (int i = (int)div.size()-1; i >= 0; i--){
        if (div[i] * div[i] == n) continue;
        div.push_back(n / div[i]);
    }
    return div;
}

int gcd(int a, int b){
    vector<int> pfactor;
    for (int k = 2; k*k <= a && k*k <= b; k++){
        while (a % k == 0 && b % k == 0) {
            pfactor.push_back(k);
            a /= k;
            b /= k;
        }
    }
    if (a != 1 && a == b) pfactor.push_back(a);
    int mul = 1;
    for (int num : pfactor) mul *= num;
    return mul;
}

int main(){
    cout << gcd(12, 20) << '\n';
    return 0;
}