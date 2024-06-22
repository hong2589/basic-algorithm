#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    char seq[20];
    bool mask[20];

    int L, C;
    cin >> L >> C;
    for (int i = 0; i < C; i++){
        cin >> seq[i];
    }
    sort(seq, seq+C);
    fill(mask, mask+C, 1);
    fill(mask, mask+L, 0);

    do {
        vector<char> V;
        for (int i = 0; i < C; i++){
            if (!mask[i]) V.push_back(seq[i]);
        }
        
        int numVowel = 0;
        int numConsonant = 0;
        for (int i = 0; i < L; i++){
            if (V[i] == 'a' || V[i] == 'i' || V[i] == 'e' || V[i] == 'o' || V[i] == 'u'){
                numVowel++;
            }
            else {
                numConsonant++;
            }
        }
        if (numVowel >= 1 && numConsonant >= 2){
            for (char v : V){
                cout << v;
            }
            cout << '\n';
        }
    } while(next_permutation(mask, mask+C));
    return 0;
}