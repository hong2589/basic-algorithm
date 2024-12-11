#include <bits/stdc++.h>
using namespace std;

vector<int> p(51,-1);
int n,m,k;
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

void show(){
    cout << "p[]: ";
    for (int i = 1; i <= n; ++i){
        cout << p[i] << ' ';
    }
    cout << '\n';
    cout << "group: ";
    for (int i = 1; i <= n; ++i){
        cout << find(i) << ' ';
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    if (k == 0){
        cout << m << '\n';
        return 0;
    }

    int truth;
    cin >> truth;
    k--;
    while (k--){
        int tmp;
        cin >> tmp;
        uni(truth, tmp);
    }

    vector<int> input[51];
    for (int i = 0; i < m; ++i){
        int q;
        cin >> q;
        while (q--){
            int tmp;
            cin >> tmp;
            input[i].push_back(tmp);
        }
    }
    for (int i = 0; i < m; ++i){
        if (input[i].size() < 2) continue;
        for (int j = 1; j < input[i].size(); ++j){
            uni(input[i][0], input[i][j]);
        }
    }

    // show();
    int ans = 0;
    for (int i = 0; i < m; ++i){
        if (find(input[i][0]) != find(truth)){
            ++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}