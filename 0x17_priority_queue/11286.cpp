#include <bits/stdc++.h>
using namespace std;

int heap[100001];
int sz = 0;

void push(int x){
    heap[++sz] = x;
    int p = sz;
    while (p != 1){
        int parent = p/2;
        if (abs(heap[p]) > abs(heap[parent])) break;
        if (abs(heap[p]) == abs(heap[parent]) && heap[p] > heap[parent]) break;
        swap(heap[p], heap[parent]);
        p = parent;
    }
}

int top(){
    return heap[1];
}

void pop(){
    swap(heap[1], heap[sz]);
    heap[sz--] = 0;
    int p = 1;
    while (2*p <= sz){
        int lc = 2*p;
        int rc = 2*p+1;
        int minc = lc;
        if (rc <= sz){
            if (abs(heap[rc]) < abs(heap[lc])) minc = rc;
            else if (abs(heap[rc]) == abs(heap[lc]) && heap[rc] < heap[lc]) minc = rc;
        }
        if (abs(heap[p]) < abs(heap[minc])) break;
        if (abs(heap[p]) == abs(heap[minc]) && heap[p] < heap[minc]) break;
        swap(heap[p], heap[minc]);
        p = minc;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        if (x == 0){
            if (sz == 0) cout << "0\n";
            else {
                cout << top() << '\n';
                pop();
            }
        }
        else {
            push(x);
        }
    }
    return 0;
}