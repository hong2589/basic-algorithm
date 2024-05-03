#include <bits/stdc++.h>
using namespace std;

void parse(deque<int>& D){
    char tmp;
    char buffer[1000000];
    cin >> buffer;
    
    char* token = strtok(buffer, "[,]");
    while (token != NULL){
        D.push_back(atoi(token));
        token = strtok(NULL, "[,]");
    }
}

void printResult(deque<int>& D, int isErr, int isReverse){
    if (isErr){
        cout << "error\n";
    }
    else {
        cout << "[";
        if (isReverse == 0){
            while (!D.empty()){
                if (D.size() == 1){
                    cout << D.front();
                    D.pop_front();
                }
                else {
                    cout << D.front() << ",";
                    D.pop_front();
                }
            }
        }
        else {
            while (!D.empty()){
                if (D.size() == 1){
                    cout << D.back();
                    D.pop_back();
                }
                else {
                    cout << D.back() << ",";
                    D.pop_back();
                }
            }
        }
        cout << "]\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        string p;
        int n;
        deque<int> D;
        
        // input
        cin >> p >> n;
        parse(D);

        // main
        int isReverse = 0;
        int isErr = 0;
        for (char op : p){
            if (op == 'R'){
                isReverse = 1 - isReverse;
            }
            else {
                if (D.empty()){
                    isErr = 1;
                    break;
                }

                if (isReverse == 0) D.pop_front();
                else D.pop_back();
            }
        }
        
        // print result
        printResult(D, isErr, isReverse);
    }
    return 0;
}