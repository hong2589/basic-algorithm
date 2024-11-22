#include <bits/stdc++.h>
using namespace std;

int p[100001];
int lc[100001];
int rc[100001];
bool vis[100001];

int travDist = 0;
int n;
vector<int> inorder_trav;

void inorder(int cur){
    if (lc[cur] != -1) inorder(lc[cur]);
    inorder_trav.push_back(cur);
    if (rc[cur] != -1) inorder(rc[cur]);
}

void pseudo_inorder(int cur){
    // cout << cur << ' ' << travDist << '\n';
    if (lc[cur] != -1 && !vis[lc[cur]]){
        p[lc[cur]] = cur;
        vis[lc[cur]] = true;
        travDist += 1;
        pseudo_inorder(lc[cur]);
    }
    else if (rc[cur] != -1 && !vis[rc[cur]]){
        p[rc[cur]] = cur;
        vis[rc[cur]] = true;
        travDist += 1;
        pseudo_inorder(rc[cur]);
    }
    else if (cur == *prev(inorder_trav.end())){
        return;
    }
    else if (p[cur] != 0){
        travDist += 1;
        pseudo_inorder(p[cur]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i){
        int cur, l, r;
        cin >> cur >> l >> r;
        lc[cur] = l;
        rc[cur] = r;
    }

    inorder(1);

    vis[1] = true;
    pseudo_inorder(1);
    cout << travDist << '\n';
    return 0;
}