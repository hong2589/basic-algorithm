#include <bits/stdc++.h>
using namespace std;

bool comp(pair<string,int> p1, pair<string,int> p2){
    return p1.second < p2.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m,n;
    unordered_map<string,int> table;
    cin >> m >> n;
    for (int i = 0; i < n; i++){
        string str;
        cin >> str;
        if (table.find(str) != table.end()){
            table.erase(str);
        }
        table[str] = i;
    }
    vector<pair<string,int>> V(table.begin(), table.end());
    sort(V.begin(), V.end(), comp);
    int size = min(m,(int)V.size());
    for (int i = 0; i < size; i++){
        cout << V[i].first << '\n';
    }
    return 0;
}