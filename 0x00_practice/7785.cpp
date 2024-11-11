#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    set<string> names;
    cin >> n;
    for (int i = 0; i < n; ++i){
        string name, state;
        cin >> name >> state;
        if (state == "enter") names.insert(name);
        else names.erase(name);
    }

    for (auto it = names.rbegin(); it != names.rend(); it++){
        cout << *it << '\n';
    }
    return 0;
}