#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int board[40][40];

void Show(int sticker[10][10], int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << sticker[i][j] << ' ';
        }
        cout << '\n';
    }
}

void rot90(int dst[10][10], int n, int m){
    int src[10][10];
    memcpy(src, dst, sizeof(int) * 100);
    memset(dst, 0, sizeof(int) * 100);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            dst[i][j] = src[n-1-j][i];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> N >> M >> K;
    for (int k = 0; k < K; k++){
        int n, m;
        int sticker[10][10];
        cin >> n >> m;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> sticker[i][j];
            }
        }
        
        for (int i = 0; i <= N-n; i++){
            for (int j = 0; j <= M-m; j++){
                bool stickerTest = true;
                for (int x = i; x <= i+n; x++){
                    for (int y = j; y <= j+m; y++){
                        if (sticker[x][y] == 1 && board[x][y] == 1){
                            stickerTest = false;
                        }
                    }
                }

                if (stickerTest){
                    for (int x = i; x <= i+n; x++){
                        for (int y = j; y <= j+m; y++){
                            board[x][y] = 1;
                        }
                    }
                }
            }
        }


    }


    return 0;
}