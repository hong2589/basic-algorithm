#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while (N--){
        char buffer[100];
        cin >> buffer;

        int len = strlen(buffer);
        stack<char> S;
        bool valid = true;
        for (int i = 0; i < len; i++){
            if (buffer[i] == '('){
                S.push(buffer[i]);
            }
            else if (buffer[i] == ')'){
                if (!S.empty() && S.top() == '('){
                    S.pop();
                }
                else {
                    valid = false;
                }
            }
        }

        if (!S.empty()) valid = false;
        
        if (valid) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}