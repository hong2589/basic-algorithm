#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int problevel[100002];
    set<int> probbylevel[102];

    cin >> N;
    for (int i = 0; i < N; ++i){
        int p, l;
        cin >> p >> l;
        problevel[p] = l;
        probbylevel[l].insert(p);
    }

    int m;
    cin >> m;
    while (m--){
        string op;
        cin >> op;
        if (op == "recommend"){
            int x;
            cin >> x;
            if (x == 1){
                for (int i = 100; i >= 1; --i){
                    if (probbylevel[i].empty()) continue;
                    cout << *prev(probbylevel[i].end()) << '\n';
                    break;
                }
            }
            else {
                for (int i = 1; i <= 100; ++i){
                    if (probbylevel[i].empty()) continue;
                    cout << *probbylevel[i].begin() << '\n';
                    break;
                }
            }
        }
        else if (op == "add"){
            int p,l;
            cin >> p >> l;
            problevel[p] = l;
            probbylevel[l].insert(p);
        }
        else {
            int p,l;
            cin >> p;
            l = problevel[p];
            probbylevel[l].erase(p);
        }
    }
    return 0;
}