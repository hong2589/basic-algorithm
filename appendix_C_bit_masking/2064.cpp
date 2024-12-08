#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> arr;
void PushIp(string& s){
    stringstream ss(s);
    string token;
    int offset = 24;
    ll val = 0;
    while (getline(ss, token, '.')){
        val |= (stoll(token) << offset);
        offset -= 8;
    }
    arr.push_back(val);
}



string cvtIp(ll x){
    int a = (x >> 24) & 0xFF;
    int b = (x >> 16) & 0xFF;
    int c = (x >> 8) & 0xFF;
    int d = x & 0xFF;
    string res = to_string(a) + "." + to_string(b) + "." + to_string(c) + "." + to_string(d);
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        string ip;
        cin >> ip;
        PushIp(ip);
    }
    
    // for (ll x : arr) cout << x << ' ';
    // cout << '\n';

    ll address = 0;
    ll mask = 0;
    for (int i = 31; i >= 0; --i){
        bool match = true;
        int key = ((arr[0] >> i) & 1);
        for (int j = 0; j < n; ++j){
            if (((arr[j] >> i) & 1) != key){
                match = false;
                break;
            }
        }

        if (match){
            address |= (key << i);
            mask |= (1 << i);
        }
        else {
            break;
        }
    }
    cout << cvtIp(address) << '\n';
    cout << cvtIp(mask) << '\n';
    return 0;
}

    