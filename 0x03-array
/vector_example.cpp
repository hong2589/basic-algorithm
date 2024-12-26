#include <bits/stdc++.h>
using namespace std;

int main(void){
    vector<int> v1(3,5); // {5, 5, 5}
    cout << v1.size() << "\n";
    v1.push_back(7); // {5, 5, 5, 7}

    vector<int> v2(2); // {0, 0}
    v2.insert(v2.begin()+1, 3); // {0, 3, 0}

    vector<int> v3 = {1, 2, 3, 4};
    v3.erase(v3.begin()+2); // {1, 2, 4}

    vector<int> v4; // {}
    v4 = v3; // {1, 2, 4}
    cout << *v4.begin() << " " << *v4.end() << "\n";
    v4.pop_back(); // {1, 2}
    cout << *v4.begin() << " " << *(v4.end()-1) << "\n";
    cout << v4.size() << "\n";
    v4.clear();
}