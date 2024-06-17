#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[100][100];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int max = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> board[i][j];
            if (board[i][j] > max) max = board[i][j];
        }
    }

    int maxNum = 0;
    for (int k = 0; k < max; k++){
        int num = 0;
        bool vis[100][100] = {};
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (vis[i][j] == 1 || board[i][j] <= k) continue;
                queue<pair<int, int>> Q;
                num += 1;
                vis[i][j] = 1;
                Q.push({i,j});
                while (!Q.empty()){
                    pair<int, int> cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++){
                        int x = cur.X + dx[dir];
                        int y = cur.Y + dy[dir];
                        if (x < 0 || x >= n || y < 0 || y >= n) continue;
                        if (vis[x][y] == 1 || board[x][y] <= k) continue;
                        vis[x][y] = 1;
                        Q.push({x,y});
                    }
                }
            }
        }
        if (num > maxNum) maxNum = num;
    }

    cout << maxNum << "\n";
    return 0;
}