#include <bits/stdc++.h>
using namespace std;

char star[3072][6144];

void printStar(int n, int x, int y){
    if (n == 3){
        star[x][y] = '*';
        star[x+1][y-1] = '*';
        star[x+1][y+1] = '*';
        for (int j = y-2; j <= y+2; j++) star[x+2][j] = '*';
        return;
    }

    int half = n / 2;
    printStar(half, x, y);
    printStar(half, x+half, y-half);
    printStar(half, x+half, y+half);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    memset(star, ' ', sizeof(star));

    printStar(n, 0, n-1);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2*n-1; j++){
            cout << star[i][j];
        }
        cout << "\n";
    }
    return 0;
}