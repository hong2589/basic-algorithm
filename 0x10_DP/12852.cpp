#include <bits/stdc++.h>
using namespace std;

unsigned int d[1000001][3];
unsigned int minArr[1000001];
unsigned int idx[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= 1000000; i++){
        fill(d[i], d[i]+3, -1);
    }

    fill(d[1], d[1]+3, 0);
    d[2][0] = 1;
    d[2][1] = 1;
    minArr[1] = 0;
    minArr[2] = 1;
    idx[2] = 0;
    for (int i = 3; i <= N; i++){
        d[i][0] = minArr[i-1] + 1;
        if (i % 2 == 0) d[i][1] = minArr[i/2]+1;
        if (i % 3 == 0) d[i][2] = minArr[i/3]+1;
        idx[i] = min_element(d[i], d[i]+3) - d[i];
        minArr[i] = *min_element(d[i], d[i]+3);
    }

    cout << minArr[N] << '\n';
    int k = N;
    while (k != 1){
        cout << k << ' ';
        if (idx[k] == 0){
            k -= 1;
        }
        else if (idx[k] == 1){
            k /= 2;
        }
        else {
            k /= 3;
        }
    }
    cout << k << '\n';
    return 0;
}