#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        string p;
        int n;
        deque<int> D;
        cin >> p >> n;
        for (int i = 0; i < n; i++){
            int input;
            cin >> input;
            D.push_back(input);
        }

        // main part
        bool reverse = 0;
        bool isErr = 0;
        for (char ch : p){
            if (ch == 'R') reverse = !reverse;
            else {
                if (D.empty()){
                    cout << "error\n";
                    isErr = 1;
                    break;
                }

                if (!reverse) D.pop_front();
                else D.pop_back();
            }
        }

        // print result
        if (isErr){
            cout << "error\n";
        }
        else {
            cout << "[";
            while (!D.empty()){
                if (D.size() != 1){
                    cout << D.front() << ", ";
                    D.pop_front();
                }
                else {
                    cout << D.front() << "]\n";
                    D.pop_front();
                }
            }
        }
        
    }
    return 0;
}