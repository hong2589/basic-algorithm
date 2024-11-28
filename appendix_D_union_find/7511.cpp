#include <bits/stdc++.h>
using namespace std;

int find(int x, vector<int>& p){
    if (p[x] < 0) return x;
    return p[x] = find(p[x],p);
}

bool uni(int u, int v, vector<int>& p){
    u = find(u,p);
    v = find(v,p);
    if (u == v) return false;
    if (p[v] < p[u]) swap(u,v);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int k = 1; k <= t; ++k){
        int n,m;
        vector<int> p(1000001, -1);
        cin >> n >> m;
        while (m--){
            int u, v;
            cin >> u >> v;
            uni(u,v,p);
        }

        int w;
        cin >> w;
        cout << "Scenario " << k << ":\n";
        while (w--){
            int u, v;
            cin >> u >> v;
            if (find(u,p) == find(v,p)) cout << "1\n";
            else cout << "0\n";
        }
        cout << '\n';
    }   
    return 0;
}