#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int arr[500000];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    int cnt = 0;
    for (int i = 0; i < N-1; i++){
        stack<int> S;
        for (int j = i+1; j < N; j++){
            if (S.empty()){
                cnt++;
                S.push(arr[j]);
            }
            else {
                if (arr[j] >= S.top()){
                    if (arr[i] >= S.top()) cnt++;
                    S.push(arr[j]);
                }
            }
        }
    } 
    cout << cnt << "\n";
    return 0;
}