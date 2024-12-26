#include <bits/stdc++.h>
using namespace std;

int d[11][11];
vector<int> adj[11];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> d[i][j];
        }
    }

    for (int k = 0; k < n; ++k){
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }

    vector<int> a;
    int ans = 100000;
    for (int i = 0; i < n; ++i){
        if (i != k) a.push_back(i);
    }

    do {
        int sum = 0;
        for (auto it = a.begin(); it != a.end(); ++it){
            int u,v;
            u = (it == a.begin())? k : *prev(it);
            v = *it;
            sum += d[u][v];
        }
        if (sum < ans) ans = sum;
    } while (next_permutation(a.begin(), a.end()));
    cout << ans << '\n';
    return 0;
}
