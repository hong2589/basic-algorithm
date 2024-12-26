#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    char buffer[100];
    cin >> buffer;

    queue<char> Q; // queue storing operators
    int len = strlen(buffer);
    for (int i = 0; i < len; i++){
        if (!isdigit(buffer[i])){
            Q.push(buffer[i]);
        }
    }
    
    char* token = strtok(buffer, "+-");
    int sum = atoi(token);
    int isMinus = 0;
    while ((token = strtok(NULL, "+-")) != NULL){
        int num = atoi(token);
        if (Q.front() == '-'){
            sum -= num;
            isMinus = 1;
            Q.pop();
        }
        else {
            if (isMinus) sum -= num;
            else sum += num;
            Q.pop();
        }
    }
    
    cout << sum << "\n";
    return 0;
}