#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;

    // init list from str
    list<char> L;
    list<char>::iterator cur = L.begin();
    for (auto ch : str){
        L.insert(cur, ch);
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++){
        char mode;
        cin >> mode;
        if (mode == 'L'){
            if (cur != L.begin()) cur--;
        }
        else if (mode == 'D'){
            if (cur != L.end()) cur++;
        }
        else if (mode == 'B'){
            if (cur != L.begin()){
                cur--;
                cur = L.erase(cur);
            }
        }
        else if (mode == 'P'){
            char ch;
            cin >> ch;
            L.insert(cur, ch);
        }
    }

    // Print all the elements of list
    for (auto ch : L) cout << ch;
    cout << "\n";
    return 0;
}