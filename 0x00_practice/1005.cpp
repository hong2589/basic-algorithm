#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[1005];
const int INF = 0x3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--){
        int n,k;
        int arr[1005];
        int target;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> arr[i];
        while (k--){
            int u,v;
            cin >> u >> v;
            adj[u].push_back({arr[v],v});
        }
        cin >> target;

        int min_val = INF;
        for (int i = 1; i <= n; ++i){
            int d[1005];
            fill(d+1, d+n, -1); // ????
            priority_queue< pair<int,int>,
                            vector<pair<int,int>>,
                            less<pair<int,int>>> pq;
            d[i] = arr[i];
            pq.push({arr[i], i});
            while (!pq.empty()){
                int w,u,dw,v;
                tie(w,u) = pq.top(); pq.pop();
                if (d[u] != w) continue;
                for (auto nxt : adj[u]){
                    tie(dw,v) = nxt;
                    if (w+dw > d[v]){
                        d[v] = w+dw;
                        pq.push({d[v], v});
                    }
                }
            }
            if (d[target] != -1 && d[target] < min_val){
                min_val = d[target];
            }
        }
        cout << min_val << '\n';
    }
    return 0;
}