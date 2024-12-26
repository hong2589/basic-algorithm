#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    stack<int> S;
    vector<char> V;
    int k = 1;
    for (int i = 0; i < N; i++){
        int val; cin >> val;
        while (k <= val){
            S.push(k);
            k++;
            V.push_back('+');
        }
        if (S.top() != val){
            cout << "NO\n";
            return 0;
        }

        S.pop();
        V.push_back('-');
    }

    for (char ch : V){
        cout << ch << "\n";
    }
    return 0;
}