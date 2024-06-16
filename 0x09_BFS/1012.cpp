#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    int T;
    cin >> T;
    while (T--){
        int board[100][100] = {};
        bool vis[100][100] = {};
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            board[x][y] = 1;
        }

        int num = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (board[i][j] == 1 && vis[i][j] != 1){
                    // Start BFS
                    num += 1;
                    queue<pair<int, int>> Q;
                    vis[i][j] = 1;
                    Q.push({i,j});
                    while (!Q.empty()){
                        pair<int, int> cur = Q.front(); Q.pop();
                        for (int dir = 0; dir < 4; dir++){
                            int x = cur.X + dx[dir];
                            int y = cur.Y + dy[dir];
                            if (x < 0 || x >= n || y < 0 || y >= m) continue;
                            if (board[x][y] != 1 || vis[x][y] == 1) continue;
                            vis[x][y] = 1;
                            Q.push({x,y});
                        }
                    }
                }
            }
        }
        cout << num << "\n";
    }
    return 0;
}