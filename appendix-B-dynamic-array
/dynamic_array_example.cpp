#include <bits/stdc++.h>
using namespace std;

int* arr;
int len = 0;
int capacity = 0;

void init(){
    arr = (int*)malloc(sizeof(int) * 1);
    capacity = 1;
}

void expand(){
    int* tmp = (int*)malloc(sizeof(int) * capacity * 2);
    for (int i = 0; i < len; ++i) tmp[i] = arr[i];
    free(arr);
    arr = tmp;
    capacity *= 2;
}

void insert(int idx, int x){
    if (len == capacity){
        expand();
    }
    for (int i = len; i > idx; --i){
        arr[i] = arr[i-1];
    }
    arr[idx] = x;
    len++;
}

