#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        pq.push(x);
    }

    long long ans = 0;
    while (pq.size() > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int c = a + b;
        ans += c;
        pq.push(c);
    }
    cout << ans << '\n';
    return 0;
}