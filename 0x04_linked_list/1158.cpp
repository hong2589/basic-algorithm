#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K;
    int arr[5001] = {};
    cin >> N >> K;
    fill(arr+1, arr+N+1, 1);

    int idx = 0;
    cout << "<";
    for (int i = 0; i < N; i++){
        for (int j = 0; j < K; j++){
            idx++;
            while (idx > N || arr[idx] == 0){
                if (idx > N) idx = 1;
                else idx++;
            }
        }
        arr[idx] = 0;
        
        if (i != N-1) cout << idx << ", ";
        else cout << idx << ">\n";
    }
    return 0;
}