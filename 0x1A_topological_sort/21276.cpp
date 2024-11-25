#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1002];
int parent[1002];
vector<int> child[1002];
int outDeg[1002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string name_list[1002];
    unordered_map<string,int> name_to_idx;
    unordered_map<int,string> idx_to_name;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> name_list[i];
    sort(name_list+1, name_list+1+n);
    for (int i = 1; i <= n; ++i){
        name_to_idx[name_list[i]] = i;
        idx_to_name[i] = name_list[i];
    }

    int m;
    cin >> m;
    while (m--){
        string name1, name2;
        int u,v;
        cin >> name1 >> name2;
        u = name_to_idx[name1];
        v = name_to_idx[name2];
        adj[u].push_back(v);
        adj[v].push_back(u);
        outDeg[u]++;
    }

    vector<int> family_king;
    for (int i = 1; i <= n; ++i){
        if (outDeg[i] == 0){
            family_king.push_back(idx_to_name[i]);
        }
    }

    cout << family_king.size() << '\n';
    for (string king : family_king){
        cout << king << ' ';
    }
    cout << '\n';

    

    
}