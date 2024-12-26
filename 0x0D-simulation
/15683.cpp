#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
char board[10][10];

int numCamera = 0;
int numWall = 0;
vector<int> V_mode;
vector<pair<int, int>> V_pos;
vector<int> V_ans;

// void Show(char board[10][10]){
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < m; j++){
//             cout << board[i][j] << ' ';
//         }
//         cout << '\n';
//     }
// }

// Draw # 
void Draw(pair<int, int> pos, int x_dir, int y_dir, char board[10][10]){
    int x = pos.X;
    int y = pos.Y;
    while (1){
        x += x_dir;
        y += y_dir;
        if (x < 0 || x >= n || y < 0 || y >= m) break;
        if (board[x][y] == '6') break;
        if (board[x][y] == '0') board[x][y] = '#';
    }
}

void func(int k, char board[10][10]){
    if (k == numCamera){
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (board[i][j] == '0') ans += 1;
            }
        }
        V_ans.push_back(ans);
        return;
    }

    char cp1[10][10], cp2[10][10], cp3[10][10], cp4[10][10];
    pair<int, int> cur = V_pos[k];
    memcpy(cp1, board, 100);
    memcpy(cp2, board, 100);
    memcpy(cp3, board, 100);
    memcpy(cp4, board, 100);
    switch(V_mode[k]){
        case 0:
            Draw(cur, 0, 1, cp1);
            Draw(cur, -1, 0, cp2);
            Draw(cur, 0, -1, cp3);
            Draw(cur, 1, 0, cp4);
            func(k+1, cp1); func(k+1, cp2); func(k+1, cp3); func(k+1, cp4);
            break;
        case 1:
            Draw(cur, 0, 1, cp1); Draw(cur, 0, -1, cp1);
            Draw(cur, -1, 0, cp2); Draw(cur, 1, 0, cp2);
            func(k+1, cp1); func(k+1, cp2);
            break;
        case 2:
            Draw(cur, 0, 1, cp1); Draw(cur, -1, 0, cp1);
            Draw(cur, -1, 0, cp2); Draw(cur, 0, -1, cp2);
            Draw(cur, 0, -1, cp3); Draw(cur, 1, 0, cp3);
            Draw(cur, 1, 0, cp4); Draw(cur, 0, 1, cp4);
            func(k+1, cp1); func(k+1, cp2); func(k+1, cp3); func(k+1, cp4);
            break;
        case 3:
            Draw(cur, -1, 0, cp1); Draw(cur, 0, -1, cp1);  Draw(cur, 1, 0, cp1);
            Draw(cur, 0, -1, cp2); Draw(cur, 1, 0, cp2);  Draw(cur, 0, 1, cp2);
            Draw(cur, 1, 0, cp3); Draw(cur, 0, 1, cp3);  Draw(cur, -1, 0, cp3);
            Draw(cur, 0, 1, cp4); Draw(cur, -1, 0, cp4);  Draw(cur, 0, -1, cp4);
            func(k+1, cp1); func(k+1, cp2); func(k+1, cp3); func(k+1, cp4);
            break;
        case 4:
            Draw(cur, 0, 1, board);
            Draw(cur, -1, 0, board);
            Draw(cur, 0, -1, board);
            Draw(cur, 1, 0, board);
            func(k+1, board); 
            break;
    }
}

int main(void){
    // input
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int val; 
            cin >> val;
            board[i][j] = val + '0';
            if (board[i][j] >= '1' && board[i][j] <= '5'){
                int mode = board[i][j] - '0' - 1; // 0 ~ 4
                numCamera++;
                V_mode.push_back(mode);
                V_pos.push_back({i,j});
            }
            if (board[i][j] == '6') numWall++;
        }
    }
    if (numCamera == 0){
        cout << n * m - numWall << '\n';
        return 0;
    }

    // main function
    func(0, board);
    sort(V_ans.begin(), V_ans.end());
    cout << *(V_ans.begin()) << '\n';
    return 0;
}