#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int cnt = 0;
    cin >> N;
    while (N--){
        char buffer[100001];
        stack<char> S;
        cin >> buffer;
        
        int len = strlen(buffer);
        for (int i = 0; i < len; i++){
            if (!S.empty() && S.top() == buffer[i]) S.pop();
            else S.push(buffer[i]);
        }

        if (S.empty()) cnt++;
    }

    cout << cnt << "\n";
    return 0;
}