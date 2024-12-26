#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K;
    cin >> K;
    int val;
    int sum = 0;
    list<int> L;
    list<int>::iterator it = L.begin();
    
    while (K--){
        cin >> val;
        if (val != 0){
            L.insert(it, val);
        }
        else {
            it--;
            it = L.erase(it);
        }
    }
    for (int val : L) sum += val;
    cout << sum << "\n";
    return 0;
}