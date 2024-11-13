#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0;

void show(){
    for (int i = 1; i <= sz; ++i){
        cout << heap[i] << ' ';
    }
    cout << '\n';
}

void swap(int* p1, int* p2){
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void push(int x){
    heap[++sz] = x;
    int p = sz;
    while (p > 1){
        if (heap[p/2] <= heap[p]) break;
        swap(&heap[p], &heap[p/2]);
        p = p/2;
    }
}

int top(){
    return heap[1];
}

void pop(){
    swap(&heap[1], &heap[sz]);
    heap[sz--] = 0;
    int p = 1;
    while (2*p <= sz){
        int lc = 2*p;
        int rc = 2*p+1;
        int min_child = (rc <= sz && heap[rc] < heap[lc])? rc : lc;
        if (heap[p] <= heap[min_child]) break;
        swap(&heap[p], &heap[min_child]);
        p = min_child;
    }
}

void test(){
    push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
    cout << top() << '\n'; // 2
    pop(); // {10, 5, 9}
    pop(); // {10, 9}
    cout << top() << '\n'; // 9
    push(5); push(15); // {10, 9, 5, 15}
    cout << top() << '\n'; // 5
    pop(); // {10, 9, 15}
    cout << top() << '\n'; // 9
}

void test2(){
    push(20); push(10); push(30);
    show();
    push(40);
    show();
    push(5);
    show();
    push(15);
    show();
}

int main(){
    test2();
    return 0;
}