#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    char buffer[100001];
    cin >> buffer;
    int len = strlen(buffer);
    list<int> L;
    list<int>::iterator it = L.begin();
    int cnt = 0;

    for (int i = 0; i < len; i++){
        if (buffer[i] == '('){
            L.insert(it, 1);
        }
        else {
            // pop
            it--;
            if (*it != 1) cnt += *it;
            it = L.erase(it); 

            // update
            for (list<int>::iterator t = L.begin(); t != L.end(); t++){
                *t += 1;
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}