#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    double x[10001];
    double y[10001];
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> x[i] >> y[i];
    }

    double area = 0;
    cout << fixed;
    cout.precision(1);
    for (int i = 1; i < n-1; ++i){
        area += (x[i]-x[0])*(y[i+1]-y[0]) - (y[i]-y[0])*(x[i+1]-x[0]);
    }
    area = abs(area);
    area /= 2;
    cout << area << '\n';
    return 0;
}