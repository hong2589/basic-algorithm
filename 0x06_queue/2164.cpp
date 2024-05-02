#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    queue<int> Q;
    for (int i = 0; i < N; i++) Q.push(i+1); 
    
    int flag = 0;
    while (Q.size() > 1){
        if (flag % 2 == 0){
            Q.pop();
        }
        else {
            int tmp = Q.front();
            Q.pop();
            Q.push(tmp);
        }
        flag++;
    }
    cout << Q.front() << "\n";
    return 0;
}