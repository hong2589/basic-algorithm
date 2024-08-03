#include <bits/stdc++.h>
using namespace std;

long long ans = 0;

void sum(vector<int> V){
    while (V.size() > 1){
        ans += *(V.end()-1) * *(V.end()-2);
        V.pop_back();
        V.pop_back();
    }
    if (V.size() == 1) ans += V[0];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<int> Vpos;
    vector<int> Vneg;
    cin >> n;
    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        if (val == 1) ans++;
        else if (val > 0) Vpos.push_back(val);
        else Vneg.push_back(val);
    }

    sort(Vpos.begin(), Vpos.end());
    sort(Vneg.begin(), Vneg.end(), greater<int>());

    sum(Vpos);
    sum(Vneg);
    cout << ans << '\n';
    return 0;
}