#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    unordered_map<string, vector<string>> t2m; // {team_name, member_names}
    unordered_map<string, string> m2t;
    for (int i = 0; i < n; i++){
        string team;
        int team_size;
        cin >> team;
        cin >> team_size;
        for (int j = 0; j < team_size; j++){
            string member;
            cin >> member;
            m2t[member] = team;
            t2m[team].push_back(member);
        }
        sort(t2m[team].begin(), t2m[team].end());
    }

    while (m--){
        string query;
        int mode;
        cin >> query;
        cin >> mode;
        if (mode == 1) cout << m2t[query] << '\n';
        else {
            for (auto member : t2m[query]){
                cout << member << '\n';
            }
        }
    }
    return 0;
}