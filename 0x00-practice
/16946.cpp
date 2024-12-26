#include <bits/stdc++.h>
using namespace std;

int n,m;
const int MX = 1000;
int board[MX][MX];

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
bool vis[MX][MX];

void bfs(int i, int j){
    queue<pair<int,int>> q;
    int cnt = 1;
    vector<pair<int,int>> walls;
    vis[i][j] = true;
    q.push({i,j});
    while (!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k){
            int x = cur.first + dx[k];
            int y = cur.second + dy[k];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (vis[x][y]) continue;
            
            if (board[x][y] == 0){
                vis[x][y] = true;
                q.push({x,y});
                cnt++;
            }
            else {
                vis[x][y] = true;
                walls.push_back({x, y});
            }
        }
    }

    for (auto wall : walls){
        board[wall.first][wall.second] += cnt;
        vis[wall.first][wall.second] = false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            char input;
            cin >> input;
            board[i][j] = input - '0';
        }
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (vis[i][j] || board[i][j] > 0) continue;
            bfs(i,j);
        }
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cout << board[i][j] % 10;
        }
        cout << '\n';
    }
    return 0;
}
