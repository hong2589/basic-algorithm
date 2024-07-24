#include <bits/stdc++.h>
using namespace std;

vector<int> primeFactors;

void prime_factorization(int n){
    for (int k = 2; k*k <= n; k++){
        while (n % k == 0){
            primeFactors.push_back(k);
            n /= k;
        }
    }
    if (n != 1) primeFactors.push_back(n);
}

int main(){
    
}