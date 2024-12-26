#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<tuple<double,int,int>> edge;
pair<int,int> coord[1001];
vector<int> p(1001,-1);

int find(int x){
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}
bool uni(int u, int v){
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (p[v] < p[u]) swap(u,v);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;
    return true;
}

double calCost(int u, int v){
    return sqrt(pow(coord[u].first-coord[v].first,2) + pow(coord[u].second-coord[v].second,2));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout << setprecision(2);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        int x,y;
        cin >> x >> y;
        coord[i] = {x,y};
    }
    while (m--){
        int u,v;
        cin >> u >> v;
        uni(u,v);
    }

    // Make edges
    if (n == 1){
        cout << 0.0 << '\n';
        return 0;
    }
    for (int i = 1; i <= n-1; ++i){
        for (int j = i+1; j <= n; ++j){
            double c = calCost(i,j);
            edge.push_back({c, i, j});
        }
    }
    sort(edge.begin(), edge.end());

    double ans = 0;
    for (int i = 0; i < edge.size(); ++i){
        double c;
        int u,v;
        tie(c,u,v) = edge[i];
        if (uni(u,v)) {
            ans += c;
        }
    }
    cout << ans << '\n';
    return 0;
}