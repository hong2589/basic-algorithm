#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<tuple<int,int,int,string>> students; // <ko, en, math, name>
    for (int i = 0; i < N; i++){
        string name;
        int ko, en, math;
        cin >> name >> ko >> en >> math;
        students.push_back({-ko, en, -math, name});
    }
    sort(students.begin(), students.end());
    for (auto student : students){
        cout << get<3>(student) << '\n';
    }
    return 0;
}