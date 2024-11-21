#include <bits/stdc++.h>
using namespace std;

int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};

void level_order_traversal(){
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        if (lc[cur]) q.push(lc[cur]);
        if (rc[cur]) q.push(rc[cur]);
    }
}

// Preorder Traversal: cur -> lc -> rc
void preorder_traversal(int cur){
    cout << cur << ' ';
    if (lc[cur]) preorder_traversal(lc[cur]);
    if (rc[cur]) preorder_traversal(rc[cur]);
}

// Inorder Traversal: lc -> cur -> rc
void inorder_traversal(int cur){
    if (lc[cur]) inorder_traversal(lc[cur]);
    cout << cur << ' ';
    if (rc[cur]) inorder_traversal(rc[cur]);
}

// Postorder Traversal: lc -> rc -> cur
void postorder_traversal(int cur){
    if (lc[cur]) postorder_traversal(lc[cur]);
    if (rc[cur]) postorder_traversal(rc[cur]);
    cout << cur << ' ';
}

int main(){
    
}