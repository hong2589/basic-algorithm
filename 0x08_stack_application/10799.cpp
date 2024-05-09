#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    char buffer[100100];
    cin >> buffer;
    
    int len = strlen(buffer);
    vector<int> V;
    int cnt = 0;

    for (int i = 0; i < len; i++){
        if (buffer[i] == '('){
            V.push_back(1);
        }
        else {
            if (V.back() == 1) {
                V.pop_back();
                for (vector<int>::iterator it = V.begin(); it != V.end(); it++){
                    *it += 1;
                }
            }
            else {
                cnt += V.back();
                V.pop_back();
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}