#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,r,m,k;
unordered_map<string,int> s2i;
vector<int> toTrav;

// 1. without ticket, 2. with ticket(discount)
const int INF = 0x3f3f3f3f;
vector<pair<int,int>> adj1[101];
vector<pair<int,int>> adj2[101];
int d1[101][101];
int d2[101][101];

int discount(string type, int cost){
    if (type == "Mugunghwa" || type == "ITX-Saemaeul" || type == "ITX-Cheongchun"){
        return 0;
    }
    else if (type == "S-Train" || type == "V-Train"){
        return cost/2;
    }
    else {
        return cost;
    }
}

void dijkstra(int st){
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq1;
    d1[st][st] = 0;
    pq1.push({0,st});
    while (!pq1.empty()){
        int w,u,dw,v;
        tie(w,u) = pq1.top(); pq1.pop();
        if (w != d1[st][u]) continue;
        for (auto nxt : adj1[u]){
            tie(dw,v) = nxt;
            if (d1[st][u] + dw < d1[st][v]){
                d1[st][v] = d1[st][u] + dw;
                pq1.push({d1[st][v], v});
            }
        }
    }

    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq2;
    d2[st][st] = 0;
    pq2.push({0,st});
    while (!pq2.empty()){
        int w,u,dw,v;
        tie(w,u) = pq2.top(); pq2.pop();
        if (w != d2[st][u]) continue;
        for (auto nxt : adj2[u]){
            tie(dw,v) = nxt;
            if (d2[st][u] + dw < d2[st][v]){
                d2[st][v] = d2[st][u] + dw;
                pq2.push({d2[st][v], v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n >> r;
    int i = 1;
    while (i <= n){
        string name;
        cin >> name;
        if (s2i.find(name) == s2i.end()){
            s2i[name] = i;
            i++;
        }
        else {
            n--;
        }
    }
    cin >> m;
    for (int i = 1; i <= m; ++i){
        string name;
        cin >> name;
        toTrav.push_back(s2i[name]);
    }
    cin >> k;
    while (k--){
        string type, u_str, v_str;
        int u,v,cost;
        cin >> type >> u_str >> v_str;
        cin >> cost;
        u = s2i[u_str]; v = s2i[v_str];
        cost *= 2;

        adj1[u].push_back({cost,v});
        adj1[v].push_back({cost,u});
        adj2[u].push_back({discount(type,cost), v});
        adj2[v].push_back({discount(type,cost), u});
    }

    // Update d1, d2
    for (int i = 1; i <= n; ++i){
        fill(d1[i]+1, d1[i]+1+n, INF);
        fill(d2[i]+1, d2[i]+1+n, INF);
    }
    for (int i = 1; i <= n; ++i){
        dijkstra(i);
    }
    
    // calculate result
    ll ans1 = 0;
    ll ans2 = r*2;
    for (int i = 0; i < toTrav.size()-1; ++i){
        int u = toTrav[i];
        int v = toTrav[i+1];
        ans1 += d1[u][v];
        ans2 += d2[u][v];
        // cout << u << ' ' << v << ' ' << d1[u][v] << ' ' << d2[u][v] << '\n';
    }
    // cout << ans1 << ' ' << ans2 << '\n';
    if (ans2 < ans1) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}