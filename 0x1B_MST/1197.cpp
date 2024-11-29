// Using Kruskal Algorithm

#include <bits/stdc++.h>
using namespace std;

tuple<int,int,int> edge[100001]; // <u,v,cost>
vector<int> p(10001,-1);
typedef long long ll;

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

bool comp(tuple<int,int,int> e1, tuple<int,int,int> e2){
    return get<2>(e1) < get<2>(e2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v,e;
    cin >> v >> e;
    for (int i = 0; i < e; ++i){
        int u,v,cost;
        cin >> u >> v >> cost;
        edge[i] = tie(u,v,cost);
    }
    sort(edge, edge+e, comp);

    ll sum = 0;
    for (int i = 0; i < e; ++i){
        int u,v,cost;
        tie(u,v,cost) = edge[i];
        if (uni(u,v)){
            sum += cost;
        }
    }
    cout << sum << '\n';
    return 0;
}