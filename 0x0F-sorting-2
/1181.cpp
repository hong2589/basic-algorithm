#include <bits/stdc++.h>
using namespace std;

bool compare(const string& a, const string& b){
    if (a.length() != b.length()) return a.length() < b.length();
    return a < b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<string> V;
    cin >> n;
    for (int i = 0; i < n; i++){
        string val;
        cin >> val;
        if (find(V.begin(), V.end(), val) == V.end()){
            V.push_back(val);
        }
    }

    sort(V.begin(), V.end(), compare);
    for (string str : V) cout << str << '\n';
    return 0;
}