#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int arr[1000000];
    int ans[1000000];
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }

    stack<int> S;
    for (int i = N-1; i >= 0; i--){
        while (!S.empty() && S.top() <= arr[i]){
            S.pop();
        }
        ans[i] = (S.empty())? -1 : S.top();
        S.push(arr[i]);
    }

    for (int i = 0; i < N; i++) cout << ans[i] << " ";
    cout << "\n";
    
    return 0;
}