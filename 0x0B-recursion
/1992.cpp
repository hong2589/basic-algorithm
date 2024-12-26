#include <bits/stdc++.h>
using namespace std;

char board[64][65];

bool Complete(int n, int r, int c){
    char val = board[r][c];
    for (int i = r; i < r+n; i++){
        for (int j = c; j < c+n; j++){
            if (board[i][j] != val) return false;
        }
    }
    return true;
}

void Compress(int n, int r, int c){
    if (n == 1 || Complete(n, r, c)){
        cout << board[r][c];
        return;
    }

    int half = n / 2;
    cout << "(";
    Compress(half, r, c);
    Compress(half, r, c+half);
    Compress(half, r+half, c);
    Compress(half, r+half, c+half);
    cout << ")";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> board[i];
    }

    Compress(n, 0, 0);
    cout << "\n";
    return 0;
}