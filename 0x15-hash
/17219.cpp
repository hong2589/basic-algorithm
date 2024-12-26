#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    unordered_map<string,string> table;
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        string addr, password;
        cin >> addr >> password;
        table[addr] = password;
    }

    while (m--){
        string addr;
        cin >> addr;
        cout << table[addr] << '\n';
    }
    return 0;
}