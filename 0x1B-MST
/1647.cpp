#include <bits/stdc++.h>
using namespace std;

int v,e;
tuple<int,int,int> edge[1000001]; // <c,u,v>
vector<int> p(100001,-1);

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
    cin >> v >> e;
    for (int i = 0; i < e; ++i){
        int u,v,c;
        cin >> u >> v >> c;
        edge[i] = tie(c,u,v);
    }
    sort(edge, edge+e);

    long long sum = 0;
    vector<int> cost;
    for (int i = 0; i < e; ++i){
        int c,u,v;
        tie(c,u,v) = edge[i];
        if (uni(u,v)){
            sum += c;
            cost.push_back(c);
        }
    }
    cout << sum - *prev(cost.end()) << '\n';
    return 0;
}
    