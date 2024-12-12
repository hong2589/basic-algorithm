#include <bits/stdc++.h>
using namespace std;

int lc[10001];
int rc[10001];
int p[10001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input p, lc, rc
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int tmp,l,r;
        cin >> tmp >> l >> r;
        lc[i] = l;
        p[l] = i;
        rc[i] = r;
        p[r] = i;
    }

    // find root
    int root;
    for (int i = 1; i <= n; ++i){
        if (p[i] == 0) root = i;
    }

    queue<int> q;
    vector<int> col;
    q.push(root);
    col.push_back(root);
    while (!q.empty()){
        int cur = q.front(); q.pop();
        int l = lc[cur];
        int r = rc[cur];
        vector<int>::iterator it = find(col.begin(), col.end(), cur);
        
        if (l != -1){
            col.insert(it,l);
            it = next(it);
            q.push(l);
        }
        if (r != -1){
            it = next(it);
            col.insert(it,r);
            q.push(r);
        }
    }
    

    for (int v : col){
        cout << v << ' ';
    }
    cout << '\n';
    return 0;
}