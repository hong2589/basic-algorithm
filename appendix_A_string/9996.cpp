#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string pattern;
    int mid;
    cin >> n;
    cin >> pattern;
    mid = pattern.find("*");

    string prefix = pattern.substr(0,mid);
    string suffix = pattern.substr(mid+1);

    while (n--){
        string name;
        cin >> name;
        if (name.size() < pattern.size()-1){
            cout << "NE\n";
            continue;
        }
        ll offset = name.size() - suffix.size();
        if (name.substr(0,mid) == prefix && 
            name.substr(offset) == suffix){
                cout << "DA\n";
        }
        else {
            cout << "NE\n";
        }
    }
    return 0;
}

