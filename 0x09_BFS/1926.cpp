#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    int n, m;
    int board[500][500];
    int vis[500][500] = {};
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int val;
            cin >> val;
            board[i][j] = val;
        }
    }

    // BFS
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<pair<int, int>> Q;
    vector<int> V;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (vis[i][j] || board[i][j] == 0) continue;
            
            vis[i][j] = 1;
            Q.push({i, j});
            int size = 0;
            while(!Q.empty()){
                pair<int, int> cur = Q.front(); Q.pop();
                // cout << "(" << cur.X << ", " << cur.Y << ")\n";
                size += 1;
                for (int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || board[nx][ny] == 0) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            V.push_back(size);
        }
    }

    sort(V.begin(), V.end());
    int maxSize = (V.empty())? 0 : V.back();
    cout << V.size() << "\n";
    cout << maxSize << "\n";
    return 0;
}