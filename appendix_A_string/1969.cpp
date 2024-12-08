#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int c2i(char c){
    switch(c){
        case 'A':
            return 0;
        case 'C':
            return 1;
        case 'G':
            return 2;
        case 'T':
            return 3;
        default:
            return -1;
    }
}
char i2c(int x){
    switch(x){
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
        default:
            return 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    vector<string> arr;
    cin >> n >> m;
    for (int i = 0; i < n; ++i){
        string x;
        cin >> x;
        arr.push_back(x);
    }

    string ans = "";
    int val = 0;
    for (int j = 0; j < m; ++j){
        vector<int> cntArr = {0,0,0,0};
        for (int i = 0; i < n; ++i){
            cntArr[c2i(arr[i][j])]++;
        }
        
        int maxIdx = max_element(cntArr.begin(), cntArr.end())-cntArr.begin();
        ans += i2c(maxIdx);
        val += n-cntArr[maxIdx];
    }
    cout << ans << '\n';
    cout << val << '\n';
    return 0;
}