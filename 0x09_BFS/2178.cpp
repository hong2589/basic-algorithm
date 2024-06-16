#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char board[102][102];
int dist[102][102];
int n, m;

int main(void){
    cin >> n >> m;
    fgetc(stdin);
    for (int i = 0; i < n; i++){
        fill(dist[i], dist[i] + m, -1);
        fgets(board[i], 102, stdin);
        board[i][strlen(board[i]) - 1] = 0;
    }


    queue<pair<int, int>> Q;
    dist[0][0] = 0;
    Q.push({0, 0});
    while (!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++){
            int x = cur.X + dx[dir];
            int y = cur.Y + dy[dir];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (dist[x][y] != -1 || board[x][y] != '1') continue;
            dist[x][y] = dist[cur.X][cur.Y] + 1;
            Q.push({x,y});
        }
    }

    cout << dist[n-1][m-1] + 1 << "\n";
    return 0;
}