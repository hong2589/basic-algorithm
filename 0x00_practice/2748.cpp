#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n){
    if (n == 1) return 1;
    else if (n == 2) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    cout << fibonacci(n) << "\n";
    return 0;
}