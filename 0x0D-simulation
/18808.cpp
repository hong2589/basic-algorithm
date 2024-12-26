#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int n, m;
int board[40][40];
int cnt = 0;

void PutSticker(int sticker[10][10]);
bool CheckPossible(int sticker[10][10], int x, int y);
void rotate(int sticker[10][10]);
void Draw(int sticker[10][10], int x, int y);
void Show(void);
void ShowSticker(int sticker[10][10]);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int k = 0; k < K; k++){
        int sticker[10][10] = {};
        cin >> n >> m;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> sticker[i][j];
            }
        }
        PutSticker(sticker);
        // Show();
    }
    cout << cnt << '\n';
}

void PutSticker(int sticker[10][10]){
    for (int rot = 0; rot < 4; rot++){
        if (n <= N && m <= M){
            bool isDraw = false;
            for (int x = 0; x+n <= N; x++){
                for (int y = 0; y+m <= M; y++){
                    if (CheckPossible(sticker, x, y)){
                        Draw(sticker, x, y);
                        isDraw = true;
                        break;
                    }
                }
                if (isDraw) break;    
            }
            if (isDraw) break;
        }
        rotate(sticker);
    }
}

bool CheckPossible(int sticker[10][10], int x, int y){
    bool isPossible = true;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (sticker[i][j] == 1 && board[x+i][y+j] == 1) isPossible = false;
        }
    }
    return isPossible;
}

void rotate(int sticker[10][10]){
    int sticker_cp[10][10];
    memcpy(sticker_cp, sticker, sizeof(int) * 100);
    memset(sticker, 0, sizeof(int) * 100);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            sticker[i][j] = sticker_cp[n-1-j][i];
        }
    }
    int tmp = n;
    n = m;
    m = tmp;
}

void Draw(int sticker[10][10], int x, int y){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (sticker[i][j] == 1){
                board[x+i][y+j] = 1;
                cnt++;
            }
        }
    }
}

void Show(void){
    cout << '\n';
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void ShowSticker(int sticker[10][10]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << sticker[i][j] << ' ';
        }
        cout << '\n';
    }
}