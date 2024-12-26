#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int board[500][500];
int vis[500][500];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    int maxSize = 0;
    int numPic = 0;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (board[i][j] == 0 || vis[i][j] == 1) continue;

            numPic++;
            int size = 0;
            queue<pair<int, int>> Q;
            vis[i][j] = 1;
            Q.push({i, j});
            while (!Q.empty()){
                size++;
                pair<int, int> cur = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++){
                    int x = cur.X + dx[dir];
                    int y = cur.Y + dy[dir];
                    if (x < 0 || x >= n || y < 0 || y >= m) continue;
                    if (board[x][y] == 0 || vis[x][y] == 1) continue;
                    vis[x][y] = 1;
                    Q.push({x, y});
                }
            }
            if (size > maxSize) maxSize = size;
        }
    }

    cout << numPic << "\n";
    cout << maxSize << "\n";
    return 0;
}