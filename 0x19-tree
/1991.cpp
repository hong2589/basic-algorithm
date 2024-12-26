#include <bits/stdc++.h>
using namespace std;

int n;
int lc[26] = {};
int rc[26] = {};

int c2i(char c){
    return c-'A';
}

char i2c(int x){
    return x+'A';
}

void preorder_traversal(int cur){
    cout << i2c(cur);
    if (lc[cur] > 0) preorder_traversal(lc[cur]);
    if (rc[cur] > 0) preorder_traversal(rc[cur]);
}

void inorder_traversal(int cur){
    if (lc[cur] > 0) inorder_traversal(lc[cur]);
    cout << i2c(cur);
    if (rc[cur] > 0) inorder_traversal(rc[cur]);
}

void postorder_traversal(int cur){
    if (lc[cur] > 0) postorder_traversal(lc[cur]);
    if (rc[cur] > 0) postorder_traversal(rc[cur]);
    cout << i2c(cur);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        char node, l, r;
        cin >> node >> l >> r;
        if (l != '.') lc[c2i(node)] = c2i(l);
        if (r != '.') rc[c2i(node)] = c2i(r);
    }
    

    preorder_traversal(0); cout << '\n';
    inorder_traversal(0); cout << '\n';
    postorder_traversal(0); cout << '\n';
    return 0;
}


