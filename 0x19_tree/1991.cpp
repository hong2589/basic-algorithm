#include <bits/stdc++.h>
using namespace std;
#define N 30
#define OFFSET 64

int p[N];
int lc[N];
int rc[N];

void preorder_traversal(int cur){
    cout << (char)(OFFSET+cur);
    if (lc[cur] != 0) preorder_traversal(lc[cur]);
    if (rc[cur] != 0) preorder_traversal(rc[cur]);
}

void inorder_traversal(int cur){
    if (lc[cur] != 0) inorder_traversal(lc[cur]);
    cout << (char)(OFFSET+cur);
    if (rc[cur] != 0) inorder_traversal(rc[cur]);
}

void postorder_traversal(int cur){
    if (lc[cur] != 0) postorder_traversal(lc[cur]);
    if (rc[cur] != 0) postorder_traversal(rc[cur]);
    cout << (char)(OFFSET+cur);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        char buffer[10];
        cin.getline(buffer, sizeof(buffer));
        // cout << buffer << '\n';
        if (buffer[2] != '.') lc[buffer[0]-OFFSET] = buffer[2]-OFFSET;
        if (buffer[4] != '.') rc[buffer[0]-OFFSET] = buffer[4]-OFFSET;
    }

    preorder_traversal(1); cout << '\n';
    inorder_traversal(1); cout << '\n';
    postorder_traversal(1); cout << '\n';
    return 0;
}


