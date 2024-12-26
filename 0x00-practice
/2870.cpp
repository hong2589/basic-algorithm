#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    char delimiter[] = "abcdefghijklmnopqrstuvwxyz";
    vector<int> V;
    cin >> N;
    while(N--){
        char buffer[1000];
        char* token;
        cin >> buffer;
        token = strtok(buffer, delimiter);
        while (token != NULL){
            int num = atoi(token);
            V.push_back(num);
            token = strtok(0, delimiter);
        }
    }
    sort(V.begin(), V.end());
    for (auto v : V) cout << v << "\n";
    return 0;
}