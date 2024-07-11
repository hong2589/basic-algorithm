#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, M;

int board[50][50];
int num_c, num_h;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    vector<pair<int,int>> pos_c;
    vector<pair<int,int>> pos_h;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> board[i][j];
            if (board[i][j] == 1){
                pos_h.push_back({i,j});
                num_h++;
            }
            else if (board[i][j] == 2){
                pos_c.push_back({i,j});
                num_c++;
            }
        }
    }

    int combArr[13] = {};
    int min_sum = 1000000;
    fill(combArr+M, combArr+num_c, 1);
    do {
        vector<pair<int,int>> V_chicken;
        for (int i = 0; i < num_c; i++){
            if (combArr[i] == 0) V_chicken.push_back(pos_c[i]);
        }

        int sum = 0;
        for (auto house : pos_h){
            int min = 100;
            for (auto chicken : V_chicken){
                int dist = abs(house.X - chicken.X) + abs(house.Y - chicken.Y);
                if (dist < min) min = dist;
            }
            sum += min;
        }

        if (sum < min_sum) min_sum = sum;
    } while (next_permutation(combArr, combArr+num_c));
    cout << min_sum << '\n';
    return 0;
}