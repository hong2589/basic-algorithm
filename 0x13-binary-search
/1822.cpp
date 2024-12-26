#include <bits/stdc++.h>
using namespace std;

int A[500000];
int B[500000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < m; i++) cin >> B[i];
    sort(A, A+n);
    sort(B, B+m);

    vector<int> V;
    for (int i = 0; i < n; i++){
        int target = A[i];
        if (!binary_search(B, B+m, target)){
            V.push_back(target);
        }
    }

    cout << V.size() << '\n';
    for (int tmp : V) cout << tmp << ' ';
    cout << '\n';
    return 0;
}