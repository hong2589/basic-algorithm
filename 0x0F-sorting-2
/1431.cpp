#include <bits/stdc++.h>
using namespace std;

string arr[50];

int sum(const string& str){
    int len = str.length();
    int cnt = 0;
    for (int i = 0; i < len; i++){
        if (str[i] >= '0' && str[i] <= '9') {
            cnt += str[i] - '0';
        }
    }
    return cnt;
}

bool compare(const string& a, const string& b){
    if (a.length() == b.length()){
        if (sum(a) == sum(b)){
            return a < b;
        }
        else return sum(a) < sum(b);
    }
    else return a.length() < b.length();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n, compare);
    for (int i = 0; i < n; i++) cout << arr[i] << '\n';
    return 0;
}