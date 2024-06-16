#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int board[1000][1000];
int dist[1000][1000];

int main(void){
    cin >> m >> n;
    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++){
        fill(dist[i], dist[i] + m, -1);
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
            if (board[i][j] == 1){
                dist[i][j] = 0;
                Q.push({i, j});
            }
        }
    }

    while (!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++){
            int x = cur.X + dx[dir];
            int y = cur.Y + dy[dir];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (board[x][y] != 0) continue;
            board[x][y] = 1;
            dist[x][y] = dist[cur.X][cur.Y] + 1;
            Q.push({x,y});
        }
    }

    bool isComplete = true;
    int maxDist = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (board[i][j] == 0) isComplete = false;
            if (dist[i][j] > maxDist) maxDist = dist[i][j];
        }
    }
    if (isComplete) cout << maxDist << "\n";
    else cout << "-1\n";
    return 0;
}