#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> DQ;

    DQ.push_front(10);
    DQ.push_back(50);
    DQ.push_front(24);

    for (auto x : DQ) cout << x << " ";
    
}