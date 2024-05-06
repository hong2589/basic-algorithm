#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    deque<int> D;
    while(N--){
        int n;
        cin >> n;
        int val;
        switch(n){
            case 1:
                cin >> val;
                D.push_front(val);
                break;
            case 2:
                cin >> val;
                D.push_back(val);
                break;
            case 3:
                if (D.empty()) cout << "-1\n";
                else {
                    cout << D.front() << "\n";
                    D.pop_front();
                }
                break;
            case 4:
                if (D.empty()) cout << "-1\n";
                else {
                    cout << D.back() << "\n";
                    D.pop_back();
                }
                break;
            case 5:
                cout << D.size() << "\n";
                break;
            case 6:
                cout << D.empty() << "\n";
                break;
            case 7:
                if (D.empty()) cout << "-1\n";
                else cout << D.front() << "\n";
                break;
            case 8:
                if (D.empty()) cout << "-1\n";
                else cout << D.back() << "\n";
                break;
        }
    }
    return 0;
}