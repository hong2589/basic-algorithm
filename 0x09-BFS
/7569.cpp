#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int dist[100][100][100];
int board[100][100][100];

int main(void){
    int n, m, h;
    cin >> m >> n >> h;

    queue<tuple<int, int, int>> Q;

    for (int k = 0; k < h; k++){
        for (int i = 0; i < n; i++){
            fill(dist[k][i], dist[k][i] + m, -1);
            for (int j = 0; j < m; j++){
                cin >> board[k][i][j];
                if (board[k][i][j] == 1){
                    dist[k][i][j] = 0;
                    Q.push({k, i, j});
                }
            }
        }
    }

    // start BFS
    while (!Q.empty()){
        tuple<int, int, int> cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 6; dir++){
            int z = get<0>(cur) + dz[dir];
            int x = get<1>(cur) + dx[dir];
            int y = get<2>(cur) + dy[dir];
            if (z < 0 || z >= h || x < 0 || x >= n || y < 0 || y >= m) continue;
            if (board[z][x][y] != 0 || dist[z][x][y] >= 0) continue;
            board[z][x][y] = 1;
            dist[z][x][y] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            Q.push({z, x, y});
        }
    }

    // checking
    int maxDist = 0;
    bool isComplete = 1;
    for (int k = 0; k < h; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (board[k][i][j] == 0) isComplete = 0;
                if (dist[k][i][j] > maxDist) maxDist = dist[k][i][j];
            }
        }
    }
    if (isComplete) cout << maxDist << "\n";
    else cout << "-1\n";
    return 0;
}