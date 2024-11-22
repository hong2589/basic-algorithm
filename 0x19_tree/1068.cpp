#include <bits/stdc++.h>
using namespace std;

int p[51];
int n;

int LeafNum(int cur){
    vector<int> child;
    bool isLeaf = true;
    for (int i = 0; i < n; ++i){
        if (p[i] == cur){
            isLeaf = false;
            child.push_back(i);
        }
    }

    if (isLeaf) return 1;
    
    int num = 0; 
    for (int c : child){
        num += LeafNum(c);
    }
    return num;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int root;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> p[i];
        if (p[i] == -1) root = i;
    }

    // cout << LeafNum(1) << '\n';

    int target;
    cin >> target;
    p[target] = -1;
    // if (p[target] == root && find(p, p+n, root) == p+n){
    //     cout << "1\n";
    //     return 0;
    // }
    if (target == root){
        cout << "0\n";
        return 0;
    }
    cout << LeafNum(root) << '\n';
    return 0;
}