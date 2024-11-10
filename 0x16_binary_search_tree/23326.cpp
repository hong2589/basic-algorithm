#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    set<int> S;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        bool chk;
        cin >> chk;
        if (chk) S.insert(i);
    } 

    int pos = 1;
    while (q--){
        int mode;
        cin >> mode;
        if (mode == 1){
            int x;
            cin >> x;
            if (S.find(x) != S.end()) S.erase(x);
            else S.insert(x);
        }
        else if (mode == 2){
            int x;
            cin >> x;
            pos = (pos-1 + x) % n + 1;
        }
        else {
            if (S.empty()){
                cout << "-1\n";
                continue;
            }
            if (S.lower_bound(pos) != S.end()){
                cout << *S.lower_bound(pos) - pos << '\n';
            }
            else {
                cout << n - pos + *S.begin() << '\n';
            }
        }
    }
    return 0;
}