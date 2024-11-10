#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--){
        multiset<int> ms;
        int k;
        cin >> k;
        while (k--){
            char op;
            int val;
            cin >> op >> val;
            if (op == 'I'){
                ms.insert(val);
            }
            else {
                if (!ms.empty()){
                    if (val == 1) ms.erase(prev(ms.end()));
                    else ms.erase(ms.begin());
                }
            }
        }

        if (ms.empty()){
            cout << "EMPTY\n";
        }
        else {
            cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
        }
    }
    return 0;
}