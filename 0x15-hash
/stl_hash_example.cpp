#include <bits/stdc++.h>
using namespace std;

void unordered_set_example(){
    unordered_set<int> s;
    s.insert(-10); s.insert(100); s.insert(15);
    s.insert(-10); // {-10, 15, 100}
    cout << s.erase(100) << '\n';
    cout << s.erase(20) << '\n';
    if (s.find(15) != s.end()) cout << "15 is in s\n";
    else cout << "15 is not in s\n";
    cout << s.size() << '\n';

    s.insert(50);
    cout << s.count(50) <<'\n';
    for (auto e : s) cout << e << '\n';
    cout << '\n';
}

void unordered_multiset_example(){
    unordered_multiset<int> ms;
    ms.insert(-10); ms.insert(100); ms.insert(15);
    ms.insert(-10); ms.insert(15);
    cout << ms.size() << '\n'; // 5
    for (auto e : ms) cout << e << ' ';
    cout << '\n';
    cout << ms.erase(-10); // {100 15 15}
    ms.erase(ms.find(-10)); // {100 15}
    ms.insert(100);
    cout << ms.count(100) << '\n'; // 2, count function use O(n)
}

void unordered_map_example(){
    unordered_map<string, int> m;
    m["hi"] = 123;
    m["bkd"] = 1000;
    m["gogo"] = 165;
    cout << m.size() << '\n'; // 3
    if (m.find("hi") != m.end()) cout << "hi in m\n";
    else cout << "hi not in m\n";
    m.erase("bkd");
    for (auto e : m) cout << e.first << ' ' << e.second << '\n';
}

int main(){
    unordered_map_example();
    return 0;
}