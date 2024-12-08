#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m;
    int set = 0;
    cin >> m;
    while (m--){
        string inst;
        cin >> inst;
        if (inst == "add"){
            int x;
            cin >> x;
            set = set | (1 << x);
        }
        else if (inst == "remove"){
            int x;
            cin >> x;
            set = set & ~(1 << x);
        }
        else if (inst == "check"){
            int x;
            cin >> x;
            cout << ((set >> x) & 1) << '\n';
        }
        else if (inst == "toggle"){
            int x;
            cin >> x;
            set = set ^ (1<<x);
        }
        else if (inst == "all"){
            set = -1;
        }
        else if (inst == "empty"){
            set = 0;
        }
    }
    return 0;
}