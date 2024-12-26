#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dist[1000000];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    
    fill(dist, dist+f, -1);
    int src = s-1;
    int dst = g-1;
    if (src == dst){
        cout << "0\n";
        return 0;
    }

    queue<int> Q;
    dist[src] = 0;
    Q.push(src);
    while (!Q.empty()){
        int cur = Q.front(); Q.pop();
        int x1 = cur + u;
        if (x1 >= 0 && x1 < f && dist[x1] < 0){
            dist[x1] = dist[cur] + 1;
            Q.push(x1);
        }
        
        int x2 = cur - d;
        if (x2 >= 0 && x2 < f && dist[x2] < 0){
            dist[x2] = dist[cur] + 1;
            Q.push(x2);
        }
    }

    if (dist[dst] >= 0) cout << dist[dst] << "\n";
    else cout << "use the stairs\n";
    return 0;
}