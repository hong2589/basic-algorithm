#include <bits/stdc++.h>
using namespace std;

int factorial(int num){
    if (num == 0) return 1;
    else return num * factorial(num-1);
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, M;
        cin >> N >> M;
        cout << factorial(M) / (factorial(N) * factorial(M-N)) << "\n";
    }
    return 0;
}