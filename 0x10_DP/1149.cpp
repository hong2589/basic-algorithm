#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int color[1000][3];
    cin >> n;
    for (int i = 0; i < n; i++){
        int r, g, b;
        cin >> r >> g >> b;
        if (i == 0){
            color[0][0] = r;
            color[0][1] = g;
            color[0][2] = b;
        }
        else {
            color[i][0] = min(color[i-1][1], color[i-1][2]) + r;
            color[i][1] = min(color[i-1][0], color[i-1][2]) + g;
            color[i][2] = min(color[i-1][0], color[i-1][1]) + b;
        }
    }
    cout << *min_element(color[n-1], color[n-1]+3) << '\n';
    return 0;
}