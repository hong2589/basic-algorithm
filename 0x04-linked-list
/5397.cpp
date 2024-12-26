#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    while (T--){
        list<char> L;
        list<char>::iterator cur = L.begin();
        string str;
        cin >> str;

        for (char ch : str){
            if (ch == '<'){
                if (cur != L.begin()) cur--;
            }
            else if (ch == '>'){
                if (cur != L.end()) cur++;
            }
            else if (ch == '-'){
                if (cur != L.begin()){
                    cur--;
                    cur = L.erase(cur);
                }
            }
            else {
                L.insert(cur, ch);
            }
        }

        // print
        for (char ch : L) cout << ch;
        cout << "\n";
    }
}