#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct _dir {
    int w,v,u,t,s,r,q,p,o,n,m;
} Dir;

Dir direction[22] = {
    {1,0,0,0,0,0,0,0,0,0,0}, {-1,0,0,0,0,0,0,0,0,0,0}, {0,1,0,0,0,0,0,0,0,0,0}, {0,-1,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0}, {0,0,-1,0,0,0,0,0,0,0,0}, {0,0,0,1,0,0,0,0,0,0,0}, {0,0,0,-1,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0}, {0,0,0,0,-1,0,0,0,0,0,0}, {0,0,0,0,0,1,0,0,0,0,0}, {0,0,0,0,0,-1,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0}, {0,0,0,0,0,0,-1,0,0,0,0}, {0,0,0,0,0,0,0,1,0,0,0}, {0,0,0,0,0,0,0,-1,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0}, {0,0,0,0,0,0,0,0,-1,0,0}, {0,0,0,0,0,0,0,0,0,1,0}, {0,0,0,0,0,0,0,0,0,-1,0},
    {0,0,0,0,0,0,0,0,0,0,1}, {0,0,0,0,0,0,0,0,0,0,-1}
};



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N, O, P, Q, R, S, T, U, V, W;
    cin >> M >> N >> O >> P >> Q >> R >> S >> T >> U >> V >> W;
    int board[W][V][U][T][S][R][Q][P][O][N][M];
    for (int w = 0; w < W; ++w) for (int v = 0; v < V; ++w) for (int u = 0; u < U; ++u) for (int t = 0; t < T; ++t) for (int s = 0; s < S; ++s) for (int r = 0; r < R; ++r)
    for (int q = 0; q < Q; ++q) for (int p = 0; p < P; ++p) for (int o = 0; o < O; ++o) for (int n = 0; n < N; ++n) for (int m = 0; m < M; ++m) cin >> board[w][v][u][t][s][r][q][p][o][n][m];

    queue<Dir> QUEUE;
    for (int w = 0; w < W; ++w) for (int v = 0; v < V; ++w) for (int u = 0; u < U; ++u) for (int t = 0; t < T; ++t) for (int s = 0; s < S; ++s) for (int r = 0; r < R; ++r)
    for (int q = 0; q < Q; ++q) for (int p = 0; p < P; ++p) for (int o = 0; o < O; ++o) for (int n = 0; n < N; ++n) for (int m = 0; m < M; ++m){
        if (board[w][v][u][t][s][r][q][p][o][n][m] == 1) QUEUE.push({w,v,u,t,s,r,q,p,o,n,m});
        while (!QUEUE.empty()){
            Dir cur = QUEUE.front();
            QUEUE.pop();
            for (int i = 0; i < 22; ++i){
                int DW, DV, DU, DT, DS, DR, DQ, DP, DO, DN, DM;
                tie(DW, DV, DU, DT, DS, DR, DQ, DP, DO, DN, DM) = direction[i];
                
            }
        }
    }
    return 0;
}

    