#include <bits/stdc++.h>
using namespace std;

int lc[10001];
int rc[10001];
int p[10001];
int levelArr[10001];
vector<int> col;


void inorder_traversal(int cur){
    if (lc[cur] != -1) inorder_traversal(lc[cur]);
    col.push_back(cur);
    if (rc[cur] != -1) inorder_traversal(rc[cur]);
}

void dfs(int cur){
    if (lc[cur] != -1){
        levelArr[lc[cur]] = levelArr[cur] + 1;
        dfs(lc[cur]);
    }
    if (rc[cur] != -1){
        levelArr[rc[cur]] = levelArr[cur] + 1;
        dfs(rc[cur]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int node,l,r;
        cin >> node >> l >> r;
        lc[node] = l;
        rc[node] = r;
        if (l != -1) p[l] = node;
        if (r != -1) p[r] = node;
    }

    // find root & fill levelArr
    int root;
    for (int i = 1; i <= n; ++i){
        if (p[i] == 0) root = i;
    }
    levelArr[root] = 1;
    dfs(root);

    inorder_traversal(root);

    int lim = *max_element(levelArr+1, levelArr+n);
    vector<int> ans;
    for (int i = 1; i <= lim; ++i){
        vector<int> row;
        for (int val : col){
            if (levelArr[val] == i) row.push_back(val);
        }
        if (row.size() == 1){
            ans.push_back(1);
        }
        else {
            ans.push_back(find(col.begin(), col.end(), *prev(row.end())) - 
                          find(col.begin(), col.end(), *row.begin()) + 1);
        }
    }

    vector<int>::iterator it = max_element(ans.begin(), ans.end());
    cout << (it-ans.begin())+1 << ' ' << *it << '\n';
    return 0;
    
}