#include <bits/stdc++.h>
using namespace std;

void EraseSound(vector<string>& sounds, string& sound){
    for (auto it = sounds.begin(); it != sounds.end();){
        if (*it == sound) sounds.erase(it);
        else ++it;
    }
}

vector<string> split(string& s){
    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, ' ')){
        tokens.push_back(token);
    }
    return tokens;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--){
        string prob;
        vector<string> sounds;
        getline(cin, prob);
        sounds = split(prob);
        while (1){
            string buffer;
            vector<string> split_buffer;
            getline(cin, buffer);
            split_buffer = split(buffer);
            if (split_buffer.size() > 3) break;
            EraseSound(sounds, split_buffer[2]);
        }
        for (string x : sounds){
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}