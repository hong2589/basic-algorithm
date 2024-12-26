#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
char board[31][31][31];
int dist[31][31][31];
int n;

void ShowDist(int l, int r, int c){
    for (int k = 0; k < l; k++){
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                cout << dist[k][i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int l, r, c;
    cin >> l >> r >> c;
    while (l != 0 || r != 0 || c != 0){
        for (int k = 0; k < l; k++){
            for (int i = 0; i < r; i++){
                cin >> board[k][i];
                fgetc(stdin);
                fill(dist[k][i], dist[k][i] + c, -1);
            }
            fgetc(stdin);
        }

        queue<tuple<int, int, int>> Q;
        int esc_x, esc_y, esc_z;
        for (int k = 0; k < l; k++){
            for (int i = 0; i < r; i++){
                for (int j = 0; j < c; j++){
                    if (board[k][i][j] == 'S'){
                        dist[k][i][j] = 0;
                        Q.push({k,i,j});
                    }
                    if (board[k][i][j] == 'E'){
                        esc_z = k;
                        esc_x = i;
                        esc_y = j;
                    }
                }
            }
        }
        while (!Q.empty()){
            tuple<int, int, int> cur = Q.front(); Q.pop();
            for (int dir = 0; dir < 6; dir++){
                int z = get<0>(cur) + dz[dir];
                int x = get<1>(cur) + dx[dir];
                int y = get<2>(cur) + dy[dir];
                if (z < 0 || z >= l || x < 0 || x >= r || y < 0 || y >= c) continue;
                if (board[z][x][y] == '#' || dist[z][x][y] >= 0) continue;
                dist[z][x][y] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                Q.push({z,x,y});
            }
        }

        if (dist[esc_z][esc_x][esc_y] >= 0){
            cout << "Escaped in " << dist[esc_z][esc_x][esc_y] << " minute(s).\n";
        }
        else {
            cout << "Trapped!\n";
        }
        cin >> l >> r >> c;
    }
    return 0;
}