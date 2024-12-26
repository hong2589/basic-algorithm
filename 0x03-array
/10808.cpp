#include <bits/stdc++.h>
using namespace std;

#define ARR_LEN 1000000

int arr[12];

int FryPossible(string& str1, string& str2){
    int cntChar1[26] = {0, };
    int cntChar2[26] = {0, };
    for (char ch : str1) cntChar1[ch - 'a'] += 1;
    for (char ch : str2) cntChar2[ch - 'a'] += 1;

    for (int i = 0; i < 26; i++){
        if (cntChar1[i] != cntChar2[i]) return 0;
    }
    return 1;
}

void ShowArr(int arr[], int len){
    for (int i = 0; i < len; i++) cout << arr[i] << " ";
    cout << "\n";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str1, str2;
    cin >> str1 >> str2;

    int cntArr1[26] = {};
    int cntArr2[26] = {};

    for (char ch : str1) cntArr1[ch - 'a'] += 1;
    for (char ch : str2) cntArr2[ch - 'a'] += 1;

    int cnt = 0;
    for (int i = 0; i < 26; i++){
        int diff = cntArr1[i] - cntArr2[i];
        cnt += (diff > 0)? diff : -diff;
    }

    
    cout << cnt << "\n";
    return 0;
}