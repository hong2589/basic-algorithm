#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    char buffer[1000];
    int len;
    cin >> buffer;
    len = strlen(buffer);

    int numOfTerm = 1;
    char op;
    for (int i = 0; i < len; i++){
        if (buffer[i] == 'x' && i+1 < len && (buffer[i+1] == '+' || buffer[i+1] == '-')){
            numOfTerm = 2;
            op = buffer[i+1];
        }
    }


    string ans = "";
    if (numOfTerm == 1){
        if (buffer[len-1] == 'x'){
            // 1차식
            char* substr = strtok(buffer, "x");
            int num = atoi(substr) / 2;
            if (num != 1 && num != -1) ans += to_string(num);
            if (num == -1) ans += "-";
            ans += "xx";
            ans += "+W";
        }
        else {
            // 0차식
            int num = atoi(buffer);
            if (num != 0){
                if (num != 1 && num != -1) ans = buffer;
                if (num == -1) ans += "-";
                ans += "x";
                ans += "+W";
            }
            else {
                ans += "W";
            }
        }
    }
    else {
        // 1+0차식
        char* leftDigit = strtok(buffer, "x");
        int lD = atoi(leftDigit) / 2;
        if (lD != 1 && lD != -1) ans += to_string(lD);
        if (lD == -1) ans += "-";
        ans += "xx";
        ans += (op == '+')? "+" : "-";

        char* rightDigit = strtok(0, "+-");
        int rD = atoi(rightDigit);
        if (rD != 0){
            if (rD != 1 && rD != -1) ans += to_string(rD);
            if (rD == -1) ans += "-";
            ans += "x";
            ans += "+W";
        }
        else {
            ans += "W";
        }
    }
    cout << ans << "\n";
    return 0;
}