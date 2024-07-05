#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string x;
    vector<string> V;
    cin >> x;
    int len = x.length();
    for (int i = 0; i < len; i++){
        string val = x.substr(i);
        V.push_back(val);
    }
    sort(V.begin(), V.end());
    for (auto v : V) cout << v << '\n';
    return 0;
}