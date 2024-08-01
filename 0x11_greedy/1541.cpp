#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    char str[55];
    queue<char> op;
    cin >> str;
    int len = strlen(str);
    for (int i = 0; i < len; i++){
        if (!isdigit(str[i])) op.push(str[i]);
    }
    
    char* token = strtok(str, "+-");
    bool plus = true;
    int sum = atoi(token);
    while ((token = strtok(0, "+-")) != 0){
        if (op.front() == '-') plus = false;
        op.pop();
        if (!plus){
            sum -= atoi(token);
        }
        else {
            sum += atoi(token);
        }
    }
    cout << sum << '\n';
    return 0;
}