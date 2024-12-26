#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> Q;
    Q.push(10); Q.push(20); Q.push(30);
    cout << Q.size() << "\n";
    cout << "Front : " << Q.front() << "\n";
    cout << "Back : " << Q.back() << "\n";

    while(!Q.empty()){
        cout << Q.front() << "\n";
        Q.pop();
    }
    return 0;
}