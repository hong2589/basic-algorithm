#include <bits/stdc++.h>
using namespace std;

int ttoi(string time){
    int hour = stoi(time.substr(0,2));
    int min = stoi(time.substr(3,2));
    return hour*60 + min;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S,E,Q;
    cin >> S >> E >> Q;
    string time,name;
    unordered_set<string> table;
    int cnt = 0;
    while (cin >> time >> name){
        int chatTime = ttoi(time);
        int S_time = ttoi(S);
        int E_time = ttoi(E);
        int Q_time = ttoi(Q);
        if (chatTime <= S_time) table.insert(name);
        if (table.find(name) != table.end() && chatTime >= E_time && chatTime <= Q_time) {
            table.erase(name);
            cnt += 1;
        }
    }
    cout << cnt << '\n';
    return 0;
}