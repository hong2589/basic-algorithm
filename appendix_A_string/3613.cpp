#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string name;
    cin >> name;
    if (name.find("_") == string::npos){
        // replace uppercase letter with _
        int pos = 0;
        if (isupper(name[pos])){
            cout << "Error!\n";
            return 0;
        }
        while (pos < name.size()){
            if (isupper(name[pos])){
                name[pos] = tolower(name[pos]);
                name.insert(pos, "_");
            }
            else {
                ++pos;
            }
        }
    }
    else {
        if (name[0] == '_'){
            cout << "Error!\n";
            return 0;
        }
        for (int i = 0; i < name.size(); ++i){
            if (isupper(name[i])){
                cout << "Error!\n";
                return 0;
            }
        }

        int pos = name.find("_");
        while (pos != string::npos){
            name.erase(pos,1);
            if (pos >= name.size() || name[pos] == '_'){
                cout << "Error!\n";
                return 0;
            }
            name[pos] = toupper(name[pos]);
            pos = name.find("_");
        }
    }
    cout << name << '\n';
    return 0;
}