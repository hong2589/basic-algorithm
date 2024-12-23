#include <bits/stdc++.h>
using namespace std;

const int MX = 10200;
const int INF = 0x3f3f3f3f;

int dx[2] = {0,1};
int dy[2] = {1,0};

char board[200][200];
vector<pair<int,int>> adj[MX];
int d[MX];

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
            }
        }
    }
}

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
            for (int k = 0; k < 2; ++k){
                int x = i+dx[k];
                int y = j+dy[k];
                if (x < 1 || x > n || y < 1 || y > m) continue;
                
                int a = c2i(board[i][j]);
                int b = c2i(board[x][y]);
                int u = m*(i-1) + j;
                int v = m*(x-1) + y;
                if (b == 1){
                    adj[u].push_back({1,v});
                    adj[v].push_back({1,u});
                }
                else {
                    adj[u].push_back({0,v});
                    adj[v].push_back({0,u});
                }
            }
        }
    }

    fill(d+1, d+1+n*m, INF);
    dijkstra(1);
    // for (int i = 1; i <= n*m; ++i) cout << d[i] << ' ';
    // cout << '\n';
    cout << d[n*m] << '\n';
    return 0;
}