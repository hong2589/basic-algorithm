#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> sites;
    vector<string> passwords;
    int N, M;

    cin >> N >> M;
    while(N--){
        char buffer[100];
        cin >> buffer;

        char* site = strtok(buffer, " ");
        char* password = strtok(0, " ");
        cout << "site : " << site << " " << "pass : " << password << "\n";
        // sites.push_back(site);
        // passwords.push_back(password);
    }
    // while(M--){
    //     char site[100];
    //     cin >> site;
        
    //     int idx = find(sites.begin(), sites.end(), site) - sites.begin();
    //     cout << passwords[idx] << "\n"; 
    // }
    return 0;
}