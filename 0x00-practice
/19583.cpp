#include <bits/stdc++.h>
using namespace std;

int convert_time(string time){
    int result = stoi(time.substr(0,2)) * 60 + stoi(time.substr(3,2));
    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s,e,q;
    cin >> s >> e >> q;
    int st = convert_time(s);
    int en1 = convert_time(e);
    int en2 = convert_time(q);

    // cout << st << ' ' << en1 << ' ' << en2 << '\n';

    string time_str, name;
    set<string> S;
    int cnt = 0;
    while (cin >> time_str >> name){
        int time = convert_time(time_str);
        if (time <= st) S.insert(name);
        else if (time >= en1 && time <= en2){
            if (S.find(name) != S.end()){
                S.erase(name);
                cnt += 1;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}