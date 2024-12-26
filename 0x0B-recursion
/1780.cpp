#include <bits/stdc++.h>
using namespace std;

int board[2187][2187];

bool Complete(int n, int r, int c){
    bool isComplete = true;
    int val = board[r][c];
    for (int i = r; i < r+n; i++){
        for (int j = c; j < c+n; j++){
            if (board[i][j] != val) isComplete = false;
        }
    }
    return isComplete;
}

tuple<int, int, int> countPaper(int n, int r, int c){
    if (n == 1 || Complete(n, r, c)){
        if (board[r][c] == -1) return {1, 0, 0};
        else if (board[r][c] == 0) return {0, 1, 0};
        else return {0, 0, 1};
    }
    
    int offset = n / 3;
    tuple<int, int, int> result = {};
    for (int i = r; i < r+n; i += offset){
        for (int j = c; j < c+n; j += offset){
            tuple<int, int, int> res = countPaper(offset, i, j);
            get<0>(result) += get<0>(res);
            get<1>(result) += get<1>(res);
            get<2>(result) += get<2>(res);
        }
    }
    // cout << "n : " << n << ", r : " << r << ", c: " << c << ", result = ";
    // cout << "<" << get<0>(result) << ", " << get<1>(result) << ", " << get<2>(result) << ">\n";
    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    tuple<int, int, int> result = countPaper(n, 0, 0);
    cout << get<0>(result) << "\n";
    cout << get<1>(result) << "\n";
    cout << get<2>(result) << "\n";
    return 0;
}