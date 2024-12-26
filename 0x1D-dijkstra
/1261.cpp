#include <bits/stdc++.h>
using namespace std;

const int MX = 10200;
const int INF = 0x3f3f3f3f;

char board[200][200];
vector<pair<int,int>> adj[MX];
int d[MX];
int pre[MX];

int c2i(char ch){
    return ch-'0';
}

void dijkstra(int st){
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    d[st] = 0;
    pq.push({0,st});
    while (!pq.empty()){
        int w,u,dw,v;
        tie(w,u) = pq.top();
        pq.pop();
        if (w != d[u]) continue;
        for (auto nxt : adj[u]){
            tie(dw,v) = nxt;
            if (w+dw < d[v]){
                d[v] = w+dw;
                pq.push({d[v],v});
                pre[v] = u;
            }
        }
    }
}
// void path_tracing(int st, int en){
//     cout << "path : \n";
//     stack<int> S;
//     while (en != st){
//         S.push(en);
//         en = pre[en];
//     }
//     S.push(st);
//     while (!S.empty()){
//         int x = S.top();
//         S.pop();
//         cout << x << ' ';
//     }
//     cout << '\n';
// }
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> m >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            int u = m*(i-1) + j;
            int v;
            int a = c2i(board[i][j]);
            int b;
            if (i < n){
                v = m*i + j;
                b = c2i(board[i+1][j]);
                adj[u].push_back({b,v});
                adj[v].push_back({a,u});
            }
            if (j < m){
                v = m*(i-1) + j+1;
                b = c2i(board[i][j+1]);
                adj[u].push_back({b,v});
                adj[v].push_back({a,u});
            }
        }
    }
    fill(d+1, d+1+n*m, INF);
    dijkstra(1);
    cout << d[n*m] << '\n';
    return 0;
}