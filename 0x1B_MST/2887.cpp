#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;

int n;
vector<tuple<int,int,int>> edge;
pair<int,int> x[100001];
pair<int,int> y[100001];
pair<int,int> z[100001];

vector<int> p(100001,-1);
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
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int cx,cy,cz;
        cin >> cx >> cy >> cz;
        x[i] = {cx,i};
        y[i] = {cy,i};
        z[i] = {cz,i};
    }
    sort(x+1, x+1+n);
    sort(y+1, y+1+n);
    sort(z+1, z+1+n);

    for (int i = 1; i < n; ++i){
        edge.push_back({abs(x[i].X-x[i+1].X), x[i].Y, x[i+1].Y});
        edge.push_back({abs(y[i].X-y[i+1].X), y[i].Y, y[i+1].Y});
        edge.push_back({abs(z[i].X-z[i+1].X), z[i].Y, z[i+1].Y});
    }
    sort(edge.begin(), edge.end());

    ll ans = 0;
    int cnt = 0;
    for (auto [c,u,v] : edge){
        if (uni(u,v)){
            ans += c;
            cnt++;
        }
        if (cnt == n-1) break;
    }
    cout << ans << '\n';
    return 0;
}