#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,K;
    pair<int,int> jewels[300000]; // <value, weight>
    multiset<int> bags;
    cin >> N >> K;
    for (int i = 0; i < N; i++){
        cin >> jewels[i].second >> jewels[i].first;
    }
    sort(jewels, jewels+N);
    for (int i = 0; i < K; i++){
        int bag;
        cin >> bag;
        bags.insert(bag);
    }

    ll sum = 0;
    for (int i = N-1; i >= 0; --i){
        int val = jewels[i].first;
        int weight = jewels[i].second;
        multiset<int>::iterator it = bags.lower_bound(weight);
        if (it == bags.end()) continue;
        sum += val;
        bags.erase(it);
    }
    cout << sum << '\n';
    return 0;
}