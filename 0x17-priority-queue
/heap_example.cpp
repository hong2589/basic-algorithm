#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> pq; // max heap, priority_queue<int, vector<int>, greater<int>> -> min heap.
    pq.push(10); pq.push(2); pq.push(5); pq.push(9);
    cout << pq.top() << '\n'; // 10
    pq.pop(); 
    cout << pq.size() << '\n';
}