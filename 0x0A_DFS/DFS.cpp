#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[500][500] = 
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}};
bool vis[500][500];
int n = 7, m = 10;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int, int>> S;
    vis[0][0] = 1;
    S.push({0,0});
    while (!S.empty()){
        pair<int, int> cur = S.top(); S.pop();
        for (int dir = 0; dir < 4; dir++){
            int x = cur.X + dx[dir];
            int y = cur.Y + dy[dir];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (board[x][y] != 1 || vis[x][y] == 1) continue;
            vis[x][y] = 1;
            S.push({x,y});
        }
    }
    return 0;
}