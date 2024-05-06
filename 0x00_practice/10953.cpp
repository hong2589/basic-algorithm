#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while (T--){
        char buffer[10];
        cin >> buffer;

        char* token = strtok(buffer, ",");
        int a = atoi(token);
        token = strtok(0, ",");
        int b = atoi(token);
        cout << a + b << "\n";
    }
    return 0;
}