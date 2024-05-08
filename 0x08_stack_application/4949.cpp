#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    char str[150];
    while (fgets(str, sizeof(str), stdin) != NULL){
        str[strlen(str)] = 0;
        if (str[0] == '.') break;

        stack<char> S;
        int len = strlen(str);
        bool isValid = true;
        for (int i = 0; i < len; i++){
            if (str[i] == '(' || str[i] == '['){
                S.push(str[i]);
            }
            else if (str[i] == ')'){
                if (!S.empty() && S.top() == '(') S.pop();
                else isValid = false;
            }
            else if (str[i] == ']'){
                if (!S.empty() && S.top() == '[') S.pop();
                else isValid = false;
            }
        } 
        if (!S.empty()) isValid = false;
        
        if (isValid) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}