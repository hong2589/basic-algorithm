#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    unordered_map<string,vector<string>> member_tb;
    unordered_map<string,string> group_tb;
    cin >> n >> m;

    for (int i = 0; i < n; ++i){
        string group_name;
        int num_mem;
        cin >> group_name;
        cin >> num_mem;
        for (int j = 0; j < num_mem; ++j){
            string name;
            cin >> name;
            member_tb[group_name].push_back(name);
            group_tb[name] = group_name;
        }
    }

    while (m--){
        string input;
        int mode;
        cin >> input >> mode;
        if (mode == 1){
            cout << group_tb[input] << '\n';
        }
        else {
            sort(member_tb[input].begin(), member_tb[input].end());
            for (string name : member_tb[input]) cout << name << '\n';
        }
    }
    return 0;
}