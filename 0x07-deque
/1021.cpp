#include <bits/stdc++.h>
using namespace std;

int findIdx(deque<int>& D, int x){
    for (int i = 0; i < D.size(); i++){
        if (D[i] == x){
            return i;
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    
    deque<int> D;
    for (int i = 0; i < N; i++) D.push_back(i+1);

    int cnt = 0;
    while (M--){
        int pos;
        int idx;
        int val;
        cin >> pos;
        idx = findIdx(D, pos);
        val = D[idx];

        int cri = (D.size() % 2 == 0)? D.size()/2 : D.size()/2+1;
        if (idx+1 > cri){
            // operation 3
            while (D.front() != val){
                int tmp = D.back();
                D.pop_back();
                D.push_front(tmp);
                cnt++;
            }
        }
        else {
            // operation 2
            while (D.front() != val){
                int tmp = D.front();
                D.pop_front();
                D.push_back(tmp);
                cnt++;
            }
        }
        D.pop_front();
        // cout << cnt << "\n";
    }

    cout << cnt << "\n";
    return 0;
}