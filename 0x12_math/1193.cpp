#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin >> x;
    int i = 1;
    while (1){
        x -= i;
        i += 1;
        if (x <= i) break;
    }
    if (x == 0){
        cout << "1/1\n";
    }
    else {
        if (i % 2 == 0){
            cout << x << '/' << i+1-x << '\n';
        }
        else {
            cout << i+1-x << '/' << x << '\n';
        }
    }
    return 0;
}