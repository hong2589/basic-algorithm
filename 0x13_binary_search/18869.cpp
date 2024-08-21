#include <bits/stdc++.h>
using namespace std;

int m, n;
int sortedSize[100][10000];
vector<vector<int>> uniq;
int comp[100][10000];

int BinarySearch(vector<int> V, int target){
    int st = 0;
    int en = n-1;
    while (st <= en){
        int mid = (st+en)/2;
        if (V[mid] < target) st = mid+1;
        else if (V[mid] > target) en = mid-1;
        else return mid;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int size[100][10000];
    cin >> m >> n;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> size[i][j];
            sortedSize[i][j] = size[i][j];
        }
        sort(sortedSize[i], sortedSize[i]+n);
    }
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (j == 0 || sortedSize[j] != sortedSize[j-1]){
                uniq[i].push_back(sortedSize[i][j]);
            }
        }
    }

    // compress
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            comp[i][j] = BinarySearch(uniq[i], size[i][j]);
        }
    }

    int cnt = 0;
    for (int i = 0; i < m-1; i++){
        for (int k = i+1; k < m; k++){
            bool same = true;
            for (int j = 0; j < n; j++){
                if (comp[i][j] != comp[k][j]) same = false;
            }
            if (same) cnt += 1;
        }
    }
    cout << cnt << '\n';
    return 0;
}