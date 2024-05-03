#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tmp_int;
    char buffer[1000];
    char tmp;
    cin >> tmp_int;
    cin >> tmp;
    cin >> buffer;
    buffer[strlen(buffer)-1] = 0;
    cout << buffer;
    return 0;
}