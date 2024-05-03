#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, L;
    int* arr;
    cin >> N >> L;
    deque<pair<int, int>> D;
    for (int i = 0; i < N; i++){
        int num;
        cin >> num;

        while(!D.empty() && D.back().second >= num){
            D.pop_back();
        }

        D.push_back({i, num});
        if (D.front().first <= i-L){
            D.pop_front();
        }

        cout << D.front().second << " ";
    }
    return 0;
}