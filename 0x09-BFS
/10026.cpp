#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    int n;
    char board[100][100];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> board[i];
    }

    bool vis1[100][100] = {};
    bool vis2[100][100] = {};
    int num1 = 0;
    int num2 = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            // case 1
            if (vis1[i][j] == 0){
                char color = board[i][j];
                num1 += 1;
                queue<pair<int, int>> Q;
                vis1[i][j] = 1;
                Q.push({i,j});
                while (!Q.empty()){
                    pair<int, int> cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++){
                        int x = cur.X + dx[dir];
                        int y = cur.Y + dy[dir];
                        if (x < 0 || x >= n || y < 0 || y >= n) continue;
                        if (vis1[x][y]) continue;
                        if (board[x][y] != color) continue;
                        vis1[x][y] = 1;
                        Q.push({x,y});
                    }
                }
            }

            // case 2
            if (vis2[i][j] == 0){
                char color = board[i][j];
                num2 += 1;
                queue<pair<int, int>> Q;
                vis2[i][j] = 1;
                Q.push({i,j});
                while (!Q.empty()){
                    pair<int, int> cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++){
                        int x = cur.X + dx[dir];
                        int y = cur.Y + dy[dir];
                        if (x < 0 || x >= n || y < 0 || y >= n) continue;
                        if (vis2[x][y]) continue;
                        if (color == 'B' && (board[x][y] == 'R' || board[x][y] == 'G')) continue;
                        if ((color == 'R' || color == 'G') && board[x][y] == 'B') continue;
                        vis2[x][y] = 1;
                        Q.push({x,y});
                    }
                }
            }
        }
    }

    cout << num1 << " " << num2 << "\n";
    return 0;
}