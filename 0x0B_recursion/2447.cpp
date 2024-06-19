#include <bits/stdc++.h>
using namespace std;

char board[2187][2188];

void Draw(int n, int r, int c, bool space){
    if (n == 1) {
        board[r][c] = (space)? ' ' : '*';
        return;
    }
    int offset = n / 3; 
    Draw(offset, r, c, space);
    Draw(offset, r, c+offset, space);
    Draw(offset, r, c+2*offset, space);

    Draw(offset, r+offset, c, space);
    Draw(offset, r+offset, c+offset, 1);
    Draw(offset, r+offset, c+2*offset, space);
   
    Draw(offset, r+2*offset, c, space);
    Draw(offset, r+2*offset, c+offset, space);
    Draw(offset, r+2*offset, c+2*offset, space);
    return;
}

int main(){
    int n;
    cin >> n;
    Draw(n, 0, 0, 0);
    for (int i = 0; i < n; i++){
        cout << board[i] << "\n";
    }
    return 0;
}