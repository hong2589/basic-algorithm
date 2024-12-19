#include <bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> edge_best;
vector<tuple<int,int,int>> edge_worst;
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

bool comp(tuple<int,int,int> t1, tuple<int,int,int> t2){
    return get<0>(t1) > get<0>(t2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    int u,v,c;
    cin >> n >> m;
    for (int i = 0; i <= m; ++i){
        cin >> u >> v >> c;
        edge_best.push_back({c,u,v});
        edge_worst.push_back({c,u,v});
    }
    sort(edge_best.begin(), edge_best.end(), comp);
    sort(edge_worst.begin(), edge_worst.end());

    int best = 0;
    for (int i = 0; i <= m; ++i){
        int c,u,v;
        tie(c,u,v) = edge_best[i];
        if (uni(u,v) && c == 0){
            best++;
        }
    }

    fill(p.begin(), p.end(), -1);
    int worst = 0;
    for (int i = 0; i <= m; ++i){
        int c,u,v;
        tie(c,u,v) = edge_worst[i];
        if (uni(u,v) && c == 0){
            worst++;
        }
    }

    best *= best;
    worst *= worst;
    cout << worst - best << '\n';
    return 0;
}