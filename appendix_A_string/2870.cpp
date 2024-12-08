#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<string> ans;

void strip_zero(string& num_str){
    int i = 0;
    while (num_str[i] == '0') i++;
    if (i == num_str.size()) num_str = "0";
    else {
        num_str = num_str.substr(i);
    }
}

void ExtractNum(string& s){
    int cur = 0;
    while (cur < s.size()){
        if (!isdigit(s[cur])){
            ++cur;
            continue;
        }

        string num_str = "";
        for (int i = 0; cur+i < s.size(); ++i){
            if (!isdigit(s[cur+i])){
                cur = cur+i;
                break;
            }
            else {
                num_str += s[cur+i];
                if (cur+i == s.size()-1) cur = s.size();
            }
        }
        strip_zero(num_str);
        ans.push_back(num_str);
    }
}

bool comp(string& a, string& b){
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    
    cin >> n;
    while (n--){
        string s;
        cin >> s;
        ExtractNum(s);
    }

    sort(ans.begin(), ans.end(), comp);
    for (string val : ans){
        cout << val << '\n';
    }
    return 0;
}