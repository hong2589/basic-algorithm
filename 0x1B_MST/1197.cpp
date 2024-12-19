// Using Kruskal Algorithm

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<tuple<int,int,int>> edge;
vector<int> p(10001, -1);

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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int u,v,c;
        cin >> u >> v >> c;
        edge.push_back({c,u,v});
    }
    sort(edge.begin(), edge.end());

    ll ans = 0;
    for (int i = 0; i < m; ++i){
        int c = get<0>(edge[i]);
        int u = get<1>(edge[i]);
        int v = get<2>(edge[i]);
        if (uni(u,v)){
            ans += c;
        }
    }
    cout << ans << '\n';
    
    return 0;
}