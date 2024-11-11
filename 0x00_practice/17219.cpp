#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;

    unordered_map<string,string> passwords; // <addr,password>
    for (int i = 0; i < n; ++i){
        string addr, password;
        cin >> addr >> password;
        passwords[addr] = password;
    }

    while(m--){
        string addr;
        cin >> addr;
        cout << passwords[addr] << '\n';
    }
    return 0;
}