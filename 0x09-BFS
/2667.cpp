#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[30][30];
int vis[30][30];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> board[i];
    }

    // BFS
    vector<int> V;
    int num = 0;
    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (board[i][j] == '0' || vis[i][j] == 1) continue;

            int size = 0;
            num += 1;
            vis[i][j] = 1;
            Q.push({i,j});
            while (!Q.empty()){
                pair<int, int> cur = Q.front(); Q.pop();
                size += 1;
                for (int dir = 0; dir < 4; dir++){
                    int x = cur.X + dx[dir];
                    int y = cur.Y + dy[dir];
                    if (x < 0 || x >= n || y < 0 || y >= n) continue;
                    if (board[x][y] == '0' || vis[x][y] == 1) continue;
                    vis[x][y] = 1;
                    Q.push({x,y});
                }
            }
            V.push_back(size);
        }
    }

    sort(V.begin(), V.end());
    cout << num << "\n";
    for (auto v : V) cout << v << "\n";
    return 0;
}