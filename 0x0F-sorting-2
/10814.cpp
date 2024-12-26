#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int,string>& a, const pair<int,string>& b){
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    vector<pair<int, string>> V;
    cin >> N;
    for (int i = 0; i < N; i++){
        int num;
        string str;
        cin >> num >> str;
        V.push_back({num, str});
    }
    stable_sort(V.begin(), V.end(), compare);
    for (auto v : V) cout << v.first << ' ' << v.second << '\n';
    return 0;
}