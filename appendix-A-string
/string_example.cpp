#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "hello";
    s += " BKD!"; // hello BKD!
    cout << s.size() << '\n'; // 10
    cout << s.substr(2,3) << '\n'; // llo
    cout << s[1] << '\n'; // e
    s.replace(6, 4, "guys"); // hello guya
    
    int it = s.find("guys"); // 6
    s.relace(it, 4, "everyone"); // hello everyone
    s.erase(7, 6); // hello ee
    s[6] = 'm'; // hello me
    s.insert(0, "say "); // say hello me
    if (s.find("to") == string::npos){
        cout << "to is not in string\n";
    }
}