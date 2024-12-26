#include <bits/stdc++.h>
using namespace std;

int N, S;
int arr[20];
int cnt = 0;

void func(int cur, int tot){
    if (cur == N){
        if (tot == S) cnt += 1;
        return;
    }
    func(cur+1, tot);
    func(cur+1, tot+arr[cur]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> arr[i];
    func(0, 0);
    if (S == 0) cout << cnt-1 << '\n';
    else cout << cnt << '\n';
    return 0;
}