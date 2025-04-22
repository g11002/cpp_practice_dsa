#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    vector<int> v = {1,2,4};
    // inserting element 3 at index 2
    cout << "inserting element 3 at index 2" << endl;
    v.insert(v.begin()+2, 3);
    for(auto it: v) {
        cout << it << " ";
    }
    cout<<endl;
    // insert the element 5 at the end of the vector
    cout << "insert the element 5 at the end of the vector" << endl;
    v.insert(v.end(), 5);
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout<<endl;
    // insert 3 zero's at the begining
    cout << "insert 3 zero's at the begining" << endl;
    v.insert(v.begin(), 3, 0);
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout<<endl;
    return 0;
}