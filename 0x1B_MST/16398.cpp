#include <bits/stdc++.h>
using namespace std;

vector<int> p(1001,-1);
vector<tuple<int,int,int>> edge; // <c,u,v>

int find(int x){
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v){
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (p[u] == p[v]) p[u]--;
    if (p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v;
    cin >> v;
    for (int i = 1; i <= v; ++i){
        for (int j = 1; j <= v; ++j){
            int x;
            cin >> x;
            if (x > 0){
                edge.push_back({x,i,j});
            }
        }
    }
    sort(edge.begin(), edge.end());

    long long sum = 0;
    for (auto e : edge){
        int c,u,v;
        tie(c,u,v) = e;
        if (uni(u,v)) sum += c;
    }
    cout << sum << '\n';
    return 0;
}