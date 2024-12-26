#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    queue<int> Q;
    while (N--){
        string inst;
        cin >> inst;
        if (inst == "push"){
            int val;
            cin >> val;
            Q.push(val);
        }
        else if (inst == "pop"){
            if (Q.empty()) cout << "-1\n";
            else {
                cout << Q.front() << "\n";
                Q.pop();
            }
        }
        else if (inst == "size"){
            cout << Q.size() << "\n";
        }
        else if (inst == "empty"){
            cout << Q.empty() << "\n";
        }
        else if (inst == "front"){
            if (Q.empty()) cout << "-1\n";
            else cout << Q.front() << "\n";
        }
        else if (inst == "back"){
            if (Q.empty()) cout << "-1\n";
            else cout << Q.back() << "\n";
        }
    }
    return 0;
}