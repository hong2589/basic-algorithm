#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--){
        int n;
        unordered_map<string,int> table;
        cin >> n;
        for (int i = 0; i < n; i++){
            string tmp, cloth;
            cin >> tmp >> cloth;
            if (table.find(cloth) == table.end()){
                table[cloth] = 1;
            }
            else {
                table[cloth] += 1;
            }
        }

        int ans = 1;
        for (auto e : table){
            ans *= e.second+1;
        }
        cout << ans-1 << '\n';
    }
}