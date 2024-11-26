#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
vector<int> ch[1001];
int indeg[1001];
unordered_map<string,int> name_to_idx;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string name_list[1001];
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> name_list[i];
    }
    sort(name_list+1, name_list+1+n);
    for (int i = 1; i <= n; ++i){
        name_to_idx[name_list[i]] = i;
    }

    int m;
    cin >> m;
    while (m--){
        string name1, name2;
        int u, v;
        cin >> name1 >> name2;
        u = name_to_idx[name1];
        v = name_to_idx[name2];
        adj[v].push_back(u);
        indeg[u]++;
    }

    vector<int> father;
    queue<int> q;
    for (int i = 1; i <= n; ++i){
        if (indeg[i] == 0){
            father.push_back(i);
            q.push(i);
        }
    }

    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int nxt : adj[cur]){
            indeg[nxt]--;
            if (indeg[nxt] == 0){
                q.push(nxt);
                ch[cur].push_back(nxt);
            }
        }
    }

    // Output
    cout << father.size() << '\n';
    for (int idx : father) cout << name_list[idx] << ' ';
    cout << '\n';
    for (int i = 1; i <= n; ++i){
        cout << name_list[i] << ' ';
        cout << ch[i].size() << ' ';
        sort(ch[i].begin(), ch[i].end());
        for (int idx : ch[i]) cout << name_list[idx] << ' ';
        cout << '\n';
    }
    return 0;
}