#include <bits/stdc++.h>
using namespace std;

int findIdx(vector<pair<string, int>>& V, string x){
    for (int i = 0; i < V.size(); i++){
        if (V[i].first == x){
            return i;
        }
    }
    return -1;
}

bool comp(pair<string, int> p1, pair<string, int> p2){
    return p1.first < p2.first;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<pair<string, int>> V;
    while(N--){
        char buffer[200];
        char* token;
        cin >> buffer;
        token = strtok(buffer, ".");
        token = strtok(NULL, ".");

        string name = token;
        int idx = findIdx(V, name);
        if (idx >= 0) V[idx].second++;
        else V.push_back({name, 1});
    }

    sort(V.begin(), V.end(), comp);
    for (int i = 0; i < V.size(); i++){
        cout << V[i].first << " " << V[i].second << "\n";
    }

    return 0;
}