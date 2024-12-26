#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[10];
int seq[10]; // candidate
bool isused[10];

void func(int k){
    if (k == m){
        for (int i = 0; i < m; i++){
            cout << seq[arr[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    int prevNum = 0;
    int st = (k == 0)? 0 : arr[k-1];
    for (int i = st; i < n; i++){
        if (!isused[i] && seq[i] != prevNum){
            arr[k] = i;
            isused[i] = 1;
            prevNum = seq[i];
            func(k+1);
            isused[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> seq[i];
    sort(seq, seq+n);
    func(0);
    return 0;
}