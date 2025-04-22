#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};
    cout << "v.size(): " << v.size() << endl;         // Number of elements
    cout << "v.capacity(): "<< v.capacity() << endl;  // Current allocated storage
    v.resize(5, 10);                                  // Resizes to 5 elements, new elements initialized with 10
    v.reserve(100);                                   // Preallocates space for 100 elements
    cout << "v.size(): " << v.size() << endl;
    cout << "v.capacity(): "<< v.capacity() << endl;

    sort(v.begin(), v.end());
    for(auto it: v) {
        cout << it << " ";
    }
    cout << endl;
    reverse(v.begin(), v.end());
    for(auto it:v) {
        cout << it << " ";
    }
    cout <<endl;
    return 0;
}