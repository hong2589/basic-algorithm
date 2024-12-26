#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[100][100];
int vis[100][100];

int n, m, k;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++){
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        for (int x = x1; x < x2; x++){
            for (int y = y1; y < y2; y++){
                board[x][y] = 1;
            }
        }
    }

    // BFS
    queue<pair<int, int>> Q;
    int num = 0;
    vector<int> V;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (board[i][j] == 1 || vis[i][j] == 1) continue;
            
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
                    if (x < 0 || x >= n || y < 0 || y >= m) continue;
                    if (board[x][y] == 1 || vis[x][y] == 1) continue;
                    vis[x][y] = 1;
                    Q.push({x,y});
                }
            }
            V.push_back(size);
        }
    }

    sort(V.begin(), V.end());
    cout << num << "\n";
    for (vector<int>::iterator it = V.begin(); it != V.end(); it++){
        cout << *it << " ";
    }
    cout << "\n";
    return 0;
}