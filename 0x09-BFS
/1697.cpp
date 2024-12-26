#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dist[100001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    fill(dist, dist+100001, -1);
    if (n == k){
        cout << "0\n";
        return 0;
    }

    queue<int> Q;
    dist[n] = 0;
    Q.push(n);
    while (!Q.empty()){
        int cur = Q.front(); Q.pop();
        int pos[3] = {cur-1, cur+1, 2*cur};
        for (int x : pos){
            if (x >= 0 && x <= 100000 && dist[x] < 0){
                if (x == k){
                    cout << dist[cur]+1 << "\n";
                    return 0;
                }
                dist[x] = dist[cur] + 1;
                Q.push(x);
            }
        }
    }
    
    return 0;
}