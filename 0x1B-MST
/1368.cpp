#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<tuple<int,int,int>> edge;
vector<int> p(301,-1);


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

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int c;
        cin >> c;
        edge.push_back({c,0,i});
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int val;
            cin >> val;
            if (j > i) edge.push_back({val,i,j});
        }
    }
    sort(edge.begin(), edge.end());

    ll ans = 0;
    for (auto e : edge){
        int c,u,v;
        tie(c,u,v) = e;
        if (uni(u,v)) ans+=c;
    }
    cout << ans << '\n';
    return 0;
}