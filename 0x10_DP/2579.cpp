#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int numStairs; cin >> numStairs;
    int D[305][3];
    int point[305];
    for (int i = 1; i <= numStairs; i++){
        cin >> point[i];
    }

    D[1][1] = point[1];
    D[1][2] = 0;
    D[2][1] = point[2];
    D[2][2] = point[1]+point[2];
    for (int i = 3; i <= numStairs; i++){
        D[i][1] = max(D[i-2][1], D[i-2][2]) + point[i];
        D[i][2] = D[i-1][1] + point[i];
    }
    cout << max(D[numStairs][1], D[numStairs][2]) << '\n';
    return 0;
}