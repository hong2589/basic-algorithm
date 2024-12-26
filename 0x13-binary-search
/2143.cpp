#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sumA[1002], sumB[1002];
vector<int> vecA, vecB;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T,n,m;
    int a[1002];
    int b[1002];

    // input
    cin >> T;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sumA[i] = sumA[i-1] + a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        sumB[i] = sumB[i-1] + b[i];
    }

    for (int i = 1; i <= n; i++){
        for (int j = 0; j < i; j++){
            vecA.push_back(sumA[i]-sumA[j]);
        }
    }
    for (int i = 1; i <= m; i++){
        for (int j = 0; j < i; j++){
            vecB.push_back(sumB[i]-sumB[j]);
        }
    }
    sort(vecA.begin(), vecA.end());
    sort(vecB.begin(), vecB.end());

    ll cnt = 0;
    for (int valA : vecA){
        cnt += upper_bound(vecB.begin(), vecB.end(), T-valA) - lower_bound(vecB.begin(), vecB.end(), T-valA);
    }
    cout << cnt << '\n';
    return 0;
}