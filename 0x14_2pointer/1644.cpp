#include <bits/stdc++.h>
using namespace std;
vector<int> primes;

bool isPrime(int n){
    if (n == 1) return false;
    for (int k = 2; k*k <= n; k++){
        if (n % k == 0) return false;
    }
    return true;
}

void makePrimes(int n){
    if (n == 1) return;
    for (int k = 2; k <= n; k++){
        if (isPrime(k)) primes.push_back(k);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    if (n == 1){
        cout << 0 << '\n';
        return 0;
    }
    makePrimes(n);

    int en = 0;
    int len = primes.size();
    int sum = primes[0];
    int cnt = 0;
    for (int st = 0; st < len; st++){
        while (en != len && sum < n){
            en++;
            if (en != len) sum += primes[en];
        }
        if (en == len) continue;
        if (sum == n) cnt++;
        sum -= primes[st];
    }
    cout << cnt << '\n';
    return 0;
}

