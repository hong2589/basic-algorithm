#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int,int>& a, const pair<int,int>& b){
    return a.first > b.first;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, C;
    cin >> N >> C;
    
    vector<pair<int,int>> V; // {cnt, num}
    for (int i = 0; i < N; i++){
        int num;
        cin >> num;
        
        bool chk = false;
        for (auto& p : V){
            if (p.second == num) {
                chk = true;
                p.first += 1;
                break;
            }
        }
        if (!chk) V.push_back({1, num});
    }

    stable_sort(V.begin(), V.end(), compare);
    for (auto p : V){
        while(p.first--) cout << p.second << ' ';
    }
    cout << '\n';
    return 0;
}