#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    pair<int,int> time[100005];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> time[i].first >> time[i].second;
    }
    sort(time, time+n, comp);

    int cnt = 0;
    int t = 0;
    for (int i = 0; i < n; i++){
        if (time[i].first >= t){
            cnt++;
            t = time[i].second;
        }
    }
    cout << cnt << '\n';
    return 0;
}