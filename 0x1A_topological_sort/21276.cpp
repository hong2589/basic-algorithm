#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> name2i;
string nameArr[1001];
vector<int> adj[1001];
vector<int> ans[1001];
vector<int> family;
int indeg[1001];

bool comp(int a, int b){
    return nameArr[a] < nameArr[b];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> nameArr[i];
    }
    sort(nameArr+1, nameArr+1+n);
    for (int i = 1; i <= n; ++i){
        name2i[nameArr[i]] = i;
    }

    int m;
    cin >> m;
    while (m--){
        string a,b;
        int u,v;
        cin >> a >> b;
        u = name2i[a];
        v = name2i[b];
        adj[v].push_back(u);
        indeg[u]++;
    }

    // root
    queue<int> q;
    for (int i = 1; i <= n; ++i){
        if (indeg[i] == 0) {
            family.push_back(i);
            q.push(i);
        }
        sort(adj[i].begin(), adj[i].end(), comp);
    }
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int nxt : adj[cur]){
            indeg[nxt]--;
            if (indeg[nxt] == 0){
                q.push(nxt);
                ans[cur].push_back(nxt);
            }
        }
    }
    
    cout << family.size() << '\n';
    for (int val : family){
        cout << nameArr[val] << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= n; ++i){
        cout << nameArr[i] << ' ';
        cout << ans[i].size() << ' ';
        for (int val : ans[i]){
            cout << nameArr[val] << ' ';
        }
        cout << '\n';
    }

    return 0;
}