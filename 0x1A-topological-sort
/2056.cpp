#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10001];
vector<int> tt[1'000'002]; // time table
int indeg[10001];
int cost[10001];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> cost[i];

        int k;
        cin >> k;
        if (k == 0) tt[cost[i]].push_back(i);
        while (k--){
            int u;
            cin >> u;
            adj[u].push_back(i);
            indeg[i]++;
        }
    }

    int ans;
    for (int cnt = 0; cnt <= 1'000'000; ++cnt){
        for (int u : tt[cnt]){
            ans = cnt;
            for (int v : adj[u]){
                indeg[v]--;
                if (indeg[v] == 0){
                    tt[cnt+cost[v]].push_back(v);
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}