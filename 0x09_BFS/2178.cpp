#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[100][100];
int dist[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        fill(dist[i], dist[i]+M, -1);
        for (int j = 0; j < M; j++){
            char val;
            cin >> val;
            board[i][j] = val-'0';
        }
        fgetc(stdin);
    }
    

    queue<pair<int, int>> Q;
    dist[0][0] = 0;
    Q.push({0,0});
    while (!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (dist[nx][ny] != -1 || board[nx][ny] == 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    cout << dist[N-1][M-1]+1 << "\n";
    return 0;
}