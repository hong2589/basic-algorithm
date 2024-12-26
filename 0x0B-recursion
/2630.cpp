#include <bits/stdc++.h>
using namespace std;

int board[128][128];

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b){
    return make_pair(a.first+b.first, a.second+b.second);
}

bool Complete(int n, int r, int c){
    int val = board[r][c];
    bool isComplete = true;
    for (int i = r; i < r+n; i++){
        for (int j = c; j < c+n; j++){
            if (board[i][j] != val) isComplete = false;
        }
    }
    return isComplete;
}

pair<int, int> CountPaper(int n, int r, int c){
    if (n == 1 || Complete(n, r, c)){
        if (board[r][c] == 0) return {1, 0};
        else return {0, 1};
    }

    int half = n / 2;
    pair<int, int> result = {0, 0};
    result = result + CountPaper(half, r, c);
    result = result + CountPaper(half, r, c+half);
    result = result + CountPaper(half, r+half, c);
    result = result + CountPaper(half, r+half, c+half);
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

    pair<int, int> res = CountPaper(n, 0, 0);
    cout << res.first << "\n";
    cout << res.second << "\n";
    return 0;
}