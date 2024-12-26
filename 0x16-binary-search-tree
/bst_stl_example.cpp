#include <bits/stdc++.h>
using namespace std;

void set_example(){
    set<int> s;
    s.insert(-10); s.insert(100); s.insert(15); // {-10, 15, 100}
    s.insert(-10); // {-10, 15, 100}
    cout << s.erase(100) << '\n'; 
    cout << s.erase(20) << '\n'; 
    if (s.find(15) != s.end()) cout << "15 in s\n";
    else cout << "15 not in s\n";
    cout << s.size() << '\n';
    cout << s.count(50) << '\n';
    for (auto e : s) cout << e << '\n';
    cout << '\n';
    s.insert(-40); // {-40, -10, 15}

    set<int>::iterator it1 = s.begin(); // {-40 <- it1, -10, 15}
    it1++; // {-40, -10 <- it1, 15}
    auto it2 = prev(it1); // -40
    it2 = next(it1); // 15
    advance(it2, -2); // -40
    auto it3 = s.lower_bound(-20); // -10
    auto it4 = s.find(15); // 15
    cout << *it1 << '\n';
    cout << *it2 << '\n';
    cout << *it3 << '\n';
    cout << *it4 << '\n';
}

void multiset_example(){
    multiset<int> ms;
    ms.insert(10); ms.insert(20); ms.insert(30); // {10, 20, 30}
    ms.insert(10); ms.insert(20); // {10, 10, 20, 20, 30}
    cout << "size : " << ms.size() << '\n'; // 5
    for (auto e : ms) cout << e << ' ';
    cout << '\n';
    cout << ms.erase(10) << '\n'; // {20, 20, 30}
    ms.erase(ms.find(20)); // {20, 30}
    ms.insert(30);
    cout << "count 30: " << ms.count(30) << '\n';

    multiset<int>::iterator it1 = ms.begin();
    auto it2 = ms.upper_bound(30); // {20, 30, 30} (<-it2)
    auto it3 = ms.find(30); // {20, 30(<-it3), 30}
    cout << *it1 << '\n'; // 20
    cout << (it2 == ms.end()) << '\n'; // 1
    cout << *it3 << '\n'; // 30
}

void map_example(){
    map<string,int> m;
    m["hi"] = 10;
    m["bkd"] = 20;
    m["gogo"] = 30;
    if (m.find("hi") != m.end()) cout << "hi in m\n";
    else cout << "hi not in m\n";
}

int main(){
    // set_example();
    multiset_example();
    return 0;
}