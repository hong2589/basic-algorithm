#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[301]; // <cost,v>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int cost[301];
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> cost[i];
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int x;
            cin >> x;
            if (x > 0){
                adj[i].push_back({x,j});
                adj[j].push_back({x,i});
            }
        }
    }

    priority_queue< tuple<int,int,int>,
                    vector<tuple<int,int,int>>,
                    greater<tuple<int,int,int>> > pq;

    int min = 1<<31-1;
    
}