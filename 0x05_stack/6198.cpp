#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N;
    cin >> N;

    vector<long long> V;
    for (long long i = 0; i < N; i++){
        long long height;
        cin >> height;
        V.push_back(height);
    }

    long long sum = 0;
    stack<pair<long long, long long>> S;
    for (long long i = V.size()-1; i >= 0; i--){
        if (S.empty()){
            S.push({V[i], 0});
        }
        else {
            long long score = 0;
            while (!S.empty() && V[i] > S.top().first){
                score += S.top().second + 1;
                S.pop();
            }
            S.push({V[i], score});
            sum += score;
        }
    }
    

    // prlong long answer
    cout << sum << "\n";

    return 0;
}