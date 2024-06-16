#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
char board[1002][1002];
int dist1[1002][1002]; // fire
int dist2[1002][1002]; // Jihoon
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        fill(dist1[i], dist1[i]+m, -1);
        fill(dist2[i], dist2[i]+m, -1);
    }
    for (int i = 0; i < n; i++){
        cin >> board[i];
    }

    queue<pair<int, int>> Q1;
    queue<pair<int, int>> Q2;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (board[i][j] == 'F'){
                dist1[i][j] = 0;
                Q1.push({i,j});
            }
            if (board[i][j] == 'J'){
                dist2[i][j] = 0;
                Q2.push({i,j});
            }
        }
    }

    while (!Q1.empty()){
        pair<int, int> cur = Q1.front(); Q1.pop();
        for (int dir = 0; dir < 4; dir++){
            int x = cur.X + dx[dir];
            int y = cur.Y + dy[dir];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (board[x][y] == '#' || dist1[x][y] >= 0) continue;
            dist1[x][y] = dist1[cur.X][cur.Y] + 1;
            Q1.push({x,y});
        }
    }
    while (!Q2.empty()){
        pair<int, int> cur = Q2.front(); Q2.pop();
        for (int dir = 0; dir < 4; dir++){
            int x = cur.X + dx[dir];
            int y = cur.Y + dy[dir];
            if (x < 0 || x >= n || y < 0 || y >= m){
                cout << dist2[cur.X][cur.Y] + 1 << "\n";
                return 0;
            }
            if (board[x][y] == '#' || dist2[x][y] >= 0) continue;
            if (dist1[x][y] >= 0 && dist1[x][y] <= dist2[cur.X][cur.Y]+1) continue;
            dist2[x][y] = dist2[cur.X][cur.Y] + 1;
            Q2.push({x,y});
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}