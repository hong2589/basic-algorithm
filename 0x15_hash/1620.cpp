#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    string i2s[100001];
    unordered_map<string,int> s2i;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        string name;
        cin >> name;
        i2s[i] = name;
        s2i[name] = i;
    }

    while (m--){
        string query;
        cin >> query;
        if (isdigit(query[0])) cout << i2s[stoi(query)] << '\n';
        else cout << s2i[query] << '\n';
    }
    return 0;
}