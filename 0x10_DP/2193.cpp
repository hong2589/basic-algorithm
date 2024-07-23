#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll d[101][2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    d[1][0] = 0; d[1][1] = 1;
    for (int i = 2; i <= 90; i++){
        d[i][0] = d[i-1][0] + d[i-1][1];
        d[i][1] = d[i-1][0];
    }

    int N;
    cin >> N;
    cout << d[N][0] + d[N][1] << '\n';
    return 0;
}