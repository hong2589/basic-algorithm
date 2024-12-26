#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    char buffer[50];
    int len;
    cin >> buffer;
    len = strlen(buffer);

    stack<char> S;
    int sum = 0;
    int mul = 1;
    bool isValid = true;
    for (int i = 0; i < len; i++){
        if (buffer[i] == '('){
            mul *= 2;
            S.push(buffer[i]);
        }
        else if (buffer[i] == '['){
            mul *= 3;
            S.push(buffer[i]);
        }
        else if (buffer[i] == ')'){
            if (S.empty() || S.top() != '(') {
                isValid = false;
                break;
            }
            if (i >= 1 && buffer[i-1] == '(') sum += mul;
            S.pop();
            mul /= 2;
        }
        else {
            if (S.empty() || S.top() != '[') {
                isValid = false;
                break;
            }
            if (i >= 1 && buffer[i-1] == '[') sum += mul;
            S.pop();
            mul /= 3;
        }
    }

    if (!S.empty()) isValid = false;

    if (isValid) cout << sum << "\n";
    else cout << "0\n";
    
    return 0;
}