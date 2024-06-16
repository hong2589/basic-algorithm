#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main(){
    int T;
    cin >> T;
    while (T--){
        int dist[300][300];
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);
        pair<int, int> src;
        pair<int, int> dest;
        cin >> src.X >> src.Y;
        cin >> dest.X >> dest.Y;
        if (src.X == dest.X && src.Y == dest.Y) cout << "0\n";

        queue<pair<int, int>> Q;
        dist[src.X][src.Y] = 0;
        Q.push(src);
        while (!Q.empty()){
            pair<int, int> cur = Q.front(); Q.pop();
            for (int dir = 0; dir < 8; dir++){
                int x = cur.X + dx[dir];
                int y = cur.Y + dy[dir];
                if (x < 0 || x >= n || y < 0 || y >= n) continue;
                if (dist[x][y] >= 0) continue;
                if (x == dest.X && y == dest.Y){
                    cout << dist[cur.X][cur.Y] + 1 << "\n";
                }
                dist[x][y] = dist[cur.X][cur.Y] + 1;
                Q.push({x,y});
            }
        }
    }
    return 0;
}