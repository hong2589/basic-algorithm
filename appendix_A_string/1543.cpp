#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a,b;
    getline(cin, a);
    getline(cin, b);

    int ans = 0;
    int cur = a.find(b);
    while (cur != string::npos){
        ++ans;
        cur = a.find(b, cur+b.size());
    }
    cout << ans << '\n';
    return 0;
}