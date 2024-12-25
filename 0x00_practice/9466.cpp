#include <bits/stdc++.h>
using namespace std;

bool isGroup[100001];
bool vis[100001];
int nxt[100001];
vector<int> V;

void dfs(int cur){
    V.push_back(cur);
    if (!vis[nxt[cur]]){
        vis[nxt[cur]] = true;
        dfs(nxt[cur]);
    }
    else {
        for (auto it = find(V.begin(), V.end(), nxt[cur]); it != V.end(); ++it){
            isGroup[*it] = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        fill(isGroup+1, isGroup+1+n, false);
        for (int i = 1; i <= n; ++i){
            int v;
            cin >> v;
            nxt[i] = v;
        }

        fill(vis+1,vis+1+n, false);
        for (int i = 1; i <= n; ++i){
            if (isGroup[i]) continue;
            if (nxt[i] == i){
                isGroup[i] = true;
                continue;
            }

            
            vis[i] = true;
            V.clear();
            dfs(i);
        }
        
        int ans = 0;
        for (int i = 1; i <= n; ++i) if(!isGroup[i]) ans++;
        cout << ans << '\n';
    }

    return 0;
}