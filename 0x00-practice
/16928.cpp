#include <bits/stdc++.h>
using namespace std;

int dist[101];
int ladders[101];
int snakes[101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    fill(dist+1, dist+101, -1);
    fill(ladders+1, ladders+101, -1);
    fill(snakes+1, snakes+101, -1);
    for (int i = 0; i < n; ++i){
        int x,y;
        cin >> x >> y;
        ladders[x] = y;
    }
    for (int i = 0; i < m; ++i){
        int x,y;
        cin >> x >> y;
        snakes[x] = y;
    }

    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int nxt = cur+1; nxt <= cur+6; ++nxt){
            if (nxt > 100) break;
            if (dist[nxt] >= 0) continue;
            dist[nxt] = dist[cur]+1;

            if (ladders[nxt] >= 0){
                int nxt2 = ladders[nxt];
                if (dist[nxt2] >= 0){
                    if (dist[nxt] < dist[nxt2]) dist[nxt2] = dist[nxt];
                }
                else dist[nxt2] = dist[nxt];
                q.push(nxt2);
            }
            else if (snakes[nxt] >= 0){
                int nxt2 = snakes[nxt];
                if (dist[nxt2] >= 0){
                    if (dist[nxt] < dist[nxt2]) dist[nxt2] = dist[nxt];
                }
                else dist[nxt2] = dist[nxt];
                q.push(nxt2);
            }
            else {
                q.push(nxt);
            }
        }
    }

    // for (int i = 0; i < 10; ++i){
    //     for (int j = 1; j <= 10; ++j){
    //         cout << dist[10*i+j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dist[100] << '\n';
    return 0;
}