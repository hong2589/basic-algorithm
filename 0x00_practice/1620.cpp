#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    unordered_map<string,int> name2n;
    unordered_map<int,string> n2name;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        string name;
        cin >> name;
        name2n[name] = i;
        n2name[i] = name;
    }

    while (m--){
        string input;
        cin >> input;
        if (isdigit(input[0])){
            cout << n2name[stoi(input)] << '\n';
        }
        else {
            cout << name2n[input] << '\n';
        }
    }
    return 0;
}