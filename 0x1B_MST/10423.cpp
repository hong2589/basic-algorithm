#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,k;
vector<int> p(1001,-1);
vector<int> power;
vector<tuple<int,int,int>> edge;

int find(int x){
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}
bool uni(int u, int v){
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (p[u] == p[v]) p[u]--;
    if (p[v] < p[u]) swap(u,v);
    p[v] = u;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    while (k--){
        int x;
        cin >> x;
        power.push_back(x);
    }
    while (m--){
        int u,v,w;
        cin >> u >> v >> w;
        edge.push_back({w,u,v});
    }
    sort(edge.begin(), edge.end());

    // solve
    if (power.size() > 1){
        for (int i = 0; i < power.size()-1; ++i){
            uni(power[i], power[i+1]);
        }
    }
    
    ll ans = 0;
    for (auto [w,u,v] : edge){
        if (uni(u,v)){
            ans += w;
        }
    }
    cout << ans << '\n';
    
    return 0;
}