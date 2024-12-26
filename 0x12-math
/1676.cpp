#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    int num5 = n / 5;
    int num25 = n / 25;
    int num125 = n / 125;
    cout << num5 + num25 + num125 << '\n';
    return 0;
}
    

