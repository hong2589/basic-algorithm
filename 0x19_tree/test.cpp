#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1,2,3,4,5};
    vector<int>::iterator it = arr.end();
    arr.insert(it,0);
    for (int x : arr) cout << x << ' ';

    it = arr.begin();
    next(it);
    cout << *it;
    cout << '\n';
    return 0;
}