#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    queue<int> Q;
    stack<int> S;
    for (int i = 0; i < N; i++){
        int val;
        cin >> val;
        Q.push(val);
    }

    int isPossible = 1;
    for (int k = 1; k <= N; k++){
        if (!S.empty() && S.top() == k){
            S.pop();
        }
        else {
            while (!Q.empty() && Q.front() != k){
                S.push(Q.front());
                Q.pop();
            }
            if (Q.empty()){
                isPossible = 0;
                break;
            }
            else {
                Q.pop();
            }
        }
    }

    if (isPossible) cout << "Nice\n";
    else cout << "Sad\n";
    return 0;
}