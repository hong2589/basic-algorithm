#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    int arr[10005];
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int en = 0;
    int sum = arr[0];
    int cnt = 0;
    for (int st = 0; st < n; st++){
        while (en != n && sum < m){
            en++;
            if (en != n) sum += arr[en];
        }
        if (en == n) continue;
        if (sum == m){
            cnt += 1;
        }
        sum -= arr[st];
    }
    cout << cnt << '\n';
    return 0;
}