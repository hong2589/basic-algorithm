#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    stack<int> S;
    cin >> N;
    while (N--){
        string inst;
        cin >> inst;
        if (inst == "push"){
            int val;
            cin >> val;
            S.push(val);
        }
        else if (inst == "pop"){
            if (S.empty()) cout << "-1\n";
            else {
                cout << S.top() << "\n";
                S.pop();
            }
        }
        else if (inst == "size"){
            cout << S.size() << "\n";
        }
        else if (inst == "empty"){
            cout << S.empty()<< "\n";
        }
        else if (inst == "top"){
            if (S.empty()) cout << "-1\n";
            else cout << S.top() << "\n";
        }
    }
    return 0;
}