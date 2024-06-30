#include <bits/stdc++.h>
using namespace std;

int arr[8] = {3, 2, 7, 4, 1, 5, 8, 6};
int n = 8;

void BubbleSort(void){
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-1-i; j++){
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

void SelectionSort(void){
    for (int i = n-1; i >= 0; i--){
        swap(arr[i], *max_element(arr, arr+i+1));
    }
}

int tmp[8]; // memory overhead for merge sort
void merge(int st, int en){
    int mid = (st+en)/2;
    int lidx = st;
    int ridx = mid;
    for (int i = st; i < en; i++){
        if (ridx >= en) tmp[i] = arr[lidx++];
        else if (lidx <= st) tmp[i] = arr[ridx++];
        else if (arr[lidx] < arr[ridx]) tmp[i] = arr[lidx++];
        else tmp[i] = arr[ridx++];
    }
    for (int i = st; i < en; i++) arr[i] = tmp[i];
}
void merge_sort(int st, int en){
    if (en == st+1) return;
    int mid = (st+en)/2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

void quick_sort(int st, int en){
    if (en == st+1) return;
    int pivot = arr[st];
    int l = st+1;
    int r = en-1;
    while (1){
        while (l <= r && arr[l] <= pivot) l++;
        while (l <= r && arr[r] > pivot) r--;
        if (r < l) break;
        swap(arr[l], arr[r]);
    }
    swap(arr[st], arr[r]);
    quick_sort(st, r);
    quick_sort(r+1, en);
}