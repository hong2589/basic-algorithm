#include <bits/stdc++.h>
using namespace std;

#define MAX_MOV 5

int N;
int board[20][20];
int max_tot = 0;

void show(int board[20][20]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void move(int board[20][20], int num, int dir){
    // main function
    int dest_board[20][20] = {};
    if (dir == 0){
        // shift right
        for (int i = 0; i < N; i++){
            for (int j = N-1; j > 0; j--){
                if (board[i][j] == 0) continue;
                int k = j-1;
                while (k >= 0 && board[i][k] == 0) k--;
                if (k < 0) continue;
                if (board[i][j] != board[i][k]) continue;
                board[i][j] *= 2;
                board[i][k] = 0;
            }
        }
        for (int i = 0; i < N; i++){
            int k = N-1;
            for (int j = N-1; j >= 0; j--){
                if (board[i][j] > 0) dest_board[i][k--] = board[i][j];
            }
        }
    }
    else if (dir == 1){
        // shift down
        for (int i = N-1; i > 0; i--){
            for (int j = 0; j < N; j++){
                if (board[i][j] == 0) continue;
                int k = i-1;
                while (k >= 0 && board[k][j] == 0) k--;
                if (k < 0) continue;
                if (board[i][j] != board[k][j]) continue;
                board[i][j] *= 2;
                board[k][j] = 0;
            }
        }
        for (int j = 0; j < N; j++){
            int k = N-1;
            for (int i = N-1; i >= 0; i--){
                if (board[i][j] > 0) dest_board[k--][j] = board[i][j];
            }
        }
    }
    else if (dir == 2){
        // shift left
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N-1; j++){
                if (board[i][j] == 0) continue;
                int k = j+1;
                while (k < N && board[i][k] == 0) k++;
                if (k > N-1) continue;
                if (board[i][j] != board[i][k]) continue;
                board[i][j] *= 2;
                board[i][k] = 0;
            }
        }
        for (int i = 0; i < N; i++){
            int k = 0;
            for (int j = 0; j < N; j++){
                if (board[i][j] > 0) dest_board[i][k++] = board[i][j];
            }
        }
    }
    else {
        //shift up
        for (int i = 0; i < N-1; i++){
            for (int j = 0; j < N; j++){
                if (board[i][j] == 0) continue;
                int k = i+1;
                while (k < N && board[k][j] == 0) k++;
                if (k > N-1) continue;
                if (board[i][j] != board[k][j]) continue;
                board[i][j] *= 2;
                board[k][j] = 0;
            }
        }
        for (int j = 0; j < N; j++){
            int k = 0;
            for (int i = 0; i < N; i++){
                if (board[i][j] > 0) dest_board[k++][j] = board[i][j];
            }
        }
    }

    // cout << '\n';
    // cout << "(" << num << "," << dir << ")\n";
    // show(dest_board);
    // cout << '\n';

    if (num == MAX_MOV - 1){
        int max = 0;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (board[i][j] > max_tot) max_tot = board[i][j];
            }
        }
        return;
    }

    // recursive part
    int cp1[20][20], cp2[20][20], cp3[20][20], cp4[20][20];
    memcpy(cp1, dest_board, sizeof(int) * 400);
    memcpy(cp2, dest_board, sizeof(int) * 400);
    memcpy(cp3, dest_board, sizeof(int) * 400);
    memcpy(cp4, dest_board, sizeof(int) * 400);
    
    move(cp1, num+1, 0);
    move(cp2, num+1, 1);
    move(cp3, num+1, 2);
    move(cp4, num+1, 3);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    int cp1[20][20], cp2[20][20], cp3[20][20], cp4[20][20];
    memcpy(cp1, board, sizeof(int) * 400);
    memcpy(cp2, board, sizeof(int) * 400);
    memcpy(cp3, board, sizeof(int) * 400);
    memcpy(cp4, board, sizeof(int) * 400);

    move(cp1, 0, 0);
    move(cp2, 0, 1);
    move(cp3, 0, 2);
    move(cp4, 0, 3);
    cout << max_tot << '\n';
    return 0;
}