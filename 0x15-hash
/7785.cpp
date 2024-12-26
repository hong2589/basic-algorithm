#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    unordered_map<string,bool> m;
    cin >> n;
    for (int i = 0; i < n; i++){
        string name;
        string enter;
        cin >> name >> enter;
        if (enter == "enter"){
            m[name] = 1;
        }
        else {
            if (m.find(name) != m.end()){
                m.erase(name);
            }
        }
    }

    vector<string> V_name;
    int size = 0;
    for (auto e : m){
        V_name.push_back(e.first);
        size++;
    }
    sort(V_name.begin(), V_name.end());
    for (int i = size-1; i >= 0; i--) cout << V_name[i] << '\n';
    return 0;
}