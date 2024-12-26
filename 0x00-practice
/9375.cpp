#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--){
        int n;
        unordered_map<string,int> table; // <cloth,num>
        cin >> n;
        for (int i = 0; i < n; ++i){
            string name, sort;
            cin >> name >> sort;
            if (table.find(sort) == table.end()) table[sort] = 1;
            else table[sort] += 1;
        }
        int ans = 1;
        for (auto e : table){
            ans *= (e.second + 1);
        }
        ans -= 1;
        cout << ans << '\n';
    }
    return 0;
}