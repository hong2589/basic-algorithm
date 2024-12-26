#include <bits/stdc++.h>
using namespace std;

vector<int> p(11,-1);

int find(int x){
    if (p[x] < 0) return x;
    return p[x] = find(p[x]); // 2. path compression opt
}

bool uni(int u, int v){
    u = find(u);
    v = find(v);

    // 1. Union by Rank opt
    if (p[v] < p[u]) swap(u,v);
    if (p[u] == p[v]) p[u]--;
    
    p[v] = u;
    return true;
}

int main(){
    
}