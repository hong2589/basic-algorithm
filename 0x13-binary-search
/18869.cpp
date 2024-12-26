#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[100][10000];
vector<int> tmp[100];
vector<int> uniq[100];
vector<int> comp[100];

int BinarySearch(vector<int> V, int target, int size){
    int st = 0;
    int en = size-1;
    while (st <= en){
        int mid = (st+en)/2;
        if (V[mid] < target) st =  mid+1;
        else if (V[mid] > target) en = mid-1;
        else return mid;
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
            tmp[i].push_back(arr[i][j]);
        }
        sort(tmp[i].begin(), tmp[i].end());
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (j == 0 || tmp[i][j] != tmp[i][j-1]){
                uniq[i].push_back(tmp[i][j]);
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            comp[i].push_back(BinarySearch(uniq[i], arr[i][j], uniq[i].size()));
        }
    }

    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cout << comp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int cnt = 0;
    for (int i = 0; i < n-1; i++){
        for (int k = i+1; k < n; k++){
            bool isSimilar = true;
            for (int j = 0; j < m; j++){
                if (comp[i][j] != comp[k][j]) isSimilar = false;
            }
            if (isSimilar) cnt += 1;
        }
    }
    cout << cnt << '\n';
    return 0;
}